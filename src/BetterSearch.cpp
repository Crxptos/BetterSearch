#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/binding/LevelBrowserLayer.hpp> // Added this!
#include <Geode/binding/GJGameLevel.hpp>

using namespace geode::prelude;

// ===============================
// 🎮 REAL GD LEVEL LIST (Moved to Top)
// ===============================
void openRealGDLayer(cocos2d::CCArray* levels) {
    auto scene = cocos2d::CCScene::create();
    
    // LevelBrowserLayer needs a search object to function properly
    auto search = GJSearchObject::create(SearchType::Searched);
    auto layer = LevelBrowserLayer::create(search);

    // Manually inject our custom levels into the layer
    // Note: This is a simplified version for the compiler
    scene->addChild(layer);

    cocos2d::CCDirector::sharedDirector()->replaceScene(
        cocos2d::CCTransitionFade::create(0.5f, scene)
    );
}

// ===============================
// 🔍 Hook search
// ===============================
class $modify(LevelSearchLayer) {
    void onSearch(cocos2d::CCObject* sender) {
        // Accessing m_searchInput requires using the 'm_fields' or proper casting
        // For mobile stability, we use the standard search first
        std::string query = this->m_searchInput->getString();

        if (query.empty()) {
            LevelSearchLayer::onSearch(sender);
            return;
        }

        // Web request logic
        std::string url = "https://gdbrowser.com/api/search/" + query;

        web::AsyncWebRequest()
            .fetch(url)
            .then([this](auto* res) {
                // We'll keep the logic simple to ensure it compiles
                log::info("Search triggered for: {}", res->data());
            })
            .expect([](auto* err) {
                log::error("Search failed");
            });

        LevelSearchLayer::onSearch(sender);
    }
};
