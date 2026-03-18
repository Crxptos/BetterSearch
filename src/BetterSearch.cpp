#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/utils/web.hpp>

#include <rapidjson/document.h>

using namespace geode::prelude;
using namespace rapidjson;

// ===============================
// 🔧 Convert JSON → GD Levels
// ===============================
cocos2d::CCArray* buildLevelsFromJSON(std::string json) {
    Document doc;
    doc.Parse(json.c_str());

    if (!doc.IsArray()) return nullptr;

    auto levels = cocos2d::CCArray::create();

    for (auto& lvl : doc.GetArray()) {
        if (!lvl.HasMember("name") || !lvl.HasMember("id"))
            continue;

        auto level = GJGameLevel::create();

        level->m_levelID = lvl["id"].GetInt();
        level->m_levelName = lvl["name"].GetString();

        // Optional polish (fake data for now)
        level->m_stars = 10;
        level->m_difficulty = 5;

        levels->addObject(level);
    }

    return levels;
}

// ===============================
// 🔍 Hook search
// ===============================
class $modify(BetterSearchLayer, LevelSearchLayer) {
    void onSearch(cocos2d::CCObject* sender) {
        std::string query = this->m_searchInput->getString();

        if (query.empty()) {
            LevelSearchLayer::onSearch(sender);
            return;
        }

        std::string encoded = query;
        std::replace(encoded.begin(), encoded.end(), ' ', '_');

        std::string url = "https://gdbrowser.com/api/search/" + encoded;

        web::AsyncWebRequest()
            .fetch(url)
            .then([this](web::WebResponse* res) {
                if (!res || res->code() != 200) {
                    log::error("Request failed");
                    return;
                }

                auto levels = buildLevelsFromJSON(res->string());

                if (!levels) {
                    log::error("No levels parsed");
                    return;
                }

                openRealGDLayer(levels);
            });

        return;
    }
};

// ===============================
// 🎮 REAL GD LEVEL LIST
// ===============================
void openRealGDLayer(cocos2d::CCArray* levels) {
    auto scene = cocos2d::CCScene::create();

    // LevelBrowserLayer is what GD uses
    auto layer = LevelBrowserLayer::create(levels);

    scene->addChild(layer);

    cocos2d::CCDirector::sharedDirector()->replaceScene(
        cocos2d::CCTransitionFade::create(0.5f, scene)
    );
}
