#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(BetterSearchSong, LevelSearchLayer) {
    CCMenuItemSpriteExtra* m_noticeBtn = nullptr;

    bool init(int p0) {
        if (!LevelSearchLayer::init(p0)) return false;

        // 🔘 Create custom image button
        auto spr = CCSprite::create("BetterSearchButton.png");

        if (!spr) {
            log::error("Failed to load BetterSearchButton.png");
        } else {
            spr->setScale(0.8f);

            m_noticeBtn = CCMenuItemSpriteExtra::create(
                spr,
                this,
                menu_selector(BetterSearchSong::onNotice)
            );

            // Adjust position to match your UI
            m_noticeBtn->setPosition({ 200, -100 });
            m_noticeBtn->setVisible(false);

            this->m_buttonMenu->addChild(m_noticeBtn);
        }

        // 📝 Set correct placeholder on load
        updateSongPlaceholder();

        return true;
    }

    // 🔄 Called when switching Normal / Custom
    void onSongFilter(CCObject* sender) {
        LevelSearchLayer::onSongFilter(sender);

        updateSongPlaceholder();
        updateButtonVisibility();
    }

    // 📝 Change placeholder text
    void updateSongPlaceholder() {
        if (!this->m_searchInput) return;

        if (this->m_customSongBtn && this->m_customSongBtn->isSelected()) {
            this->m_searchInput->setPlaceholder("Enter Song Name");
        } else {
            this->m_searchInput->setPlaceholder("Enter Song ID");
        }
    }

    // 👁️ Show/hide button
    void updateButtonVisibility() {
        if (!m_noticeBtn) return;

        if (this->m_customSongBtn && this->m_customSongBtn->isSelected()) {
            m_noticeBtn->setVisible(true);
        } else {
            m_noticeBtn->setVisible(false);
        }
    }

    // 🧠 Button click → popup
    void onNotice(CCObject*) {
        FLAlertLayer::create(
            "NOTICE",
            "This mod lets you search up songs by the name, <cr>NOT</c> the ID.",
            "OK"
        )->show();
    }
};
