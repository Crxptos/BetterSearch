#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(BetterSearchSong, LevelSearchLayer) {
    struct Fields {
        CCMenuItemSpriteExtra* m_noticeBtn = nullptr;
    };

    bool init(int p0) {
        if (!LevelSearchLayer::init(p0)) return false;

        // 🔘 Create custom image button
        auto spr = CCSprite::create("BetterSearchButton.png");

        if (!spr) {
            log::error("Failed to load BetterSearchButton.png");
        } else {
            spr->setScale(0.8f);

            m_fields->m_noticeBtn = CCMenuItemSpriteExtra::create(
                spr,
                this,
                menu_selector(BetterSearchSong::onNotice)
            );

            m_fields->m_noticeBtn->setPosition({ 200, -100 });
            m_fields->m_noticeBtn->setVisible(true);

            // ⚠️ safer than m_buttonMenu
            this->addChild(m_fields->m_noticeBtn);
        }

        return true;
    }

    void onNotice(CCObject*) {
        FLAlertLayer::create(
            "NOTICE",
            "This mod lets you search songs by name, not ID.",
            "OK"
        )->show();
    }
};
