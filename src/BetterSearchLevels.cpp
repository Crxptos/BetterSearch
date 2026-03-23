#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/ui/ScrollLayer.hpp>

using namespace geode::prelude;

class $modify(BetterSearchLevels, LevelSearchLayer) {
    struct Fields {
        ScrollLayer* m_scroll = nullptr;
        CCLayer* m_content = nullptr;
        std::vector<std::string> m_results;
    };

    bool init(int p0) {
        if (!LevelSearchLayer::init(p0)) return false;

        // 📜 Scroll area
        m_fields->m_scroll = ScrollLayer::create({300, 200});
        m_fields->m_scroll->setPosition({50, 100});
        this->addChild(m_fields->m_scroll);

        // 📦 Content layer
        m_fields->m_content = CCLayer::create();
        m_fields->m_scroll->m_contentLayer->addChild(m_fields->m_content);

        return true;
    }

    void updateBetterSearchUI(std::vector<std::string> results) {
        m_fields->m_results = results;

        m_fields->m_content->removeAllChildren();

        float y = static_cast<float>(results.size() * 35);

        for (int i = 0; i < results.size(); i++) {
            auto bg = CCScale9Sprite::create("square02_small.png");
            bg->setContentSize({280, 30});
            bg->setOpacity(i % 2 == 0 ? 40 : 60);

            auto label = CCLabelBMFont::create(results[i].c_str(), "bigFont.fnt");
            label->setAnchorPoint({0, 0.5f});
            label->setPosition({10, 15});
            label->setScale(0.5f);

            bg->addChild(label);

            auto btn = CCMenuItemSpriteExtra::create(
                bg,
                this,
                menu_selector(BetterSearchLevels::onResult)
            );

            btn->setTag(i);
            btn->setPosition({150, y});

            // ✅ SAFE (no m_buttonMenu)
            this->addChild(btn);

            y -= 35;
        }

        m_fields->m_content->setContentSize({
            300,
            static_cast<float>(results.size() * 35)
        });

        m_fields->m_scroll->updateLayout();
    }

    void onResult(CCObject* sender) {
        auto btn = static_cast<CCMenuItemSpriteExtra*>(sender);
        int index = btn->getTag();

        if (index < 0 || index >= m_fields->m_results.size()) return;

        std::string selected = m_fields->m_results[index];

        log::info("Selected: {}", selected);

        this->m_searchInput->setString(selected.c_str());

        LevelSearchLayer::onSearch(nullptr);
    }
};
