#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(BetterSearchSong, LevelSearchLayer) {

    bool init(int p0) {
        if (!LevelSearchLayer::init(p0)) return false;

        updateSongPlaceholder();

        return true;
    }

    // Runs when switching Normal / Custom
    void onSongFilter(CCObject* sender) {
        LevelSearchLayer::onSongFilter(sender);

        updateSongPlaceholder();
    }

    void updateSongPlaceholder() {
        if (!this->m_searchInput) return;

        // Check if Custom is selected
        if (this->m_customSongBtn && this->m_customSongBtn->isSelected()) {
            this->m_searchInput->setPlaceholder("Enter Song Name");
        } else {
            this->m_searchInput->setPlaceholder("Enter Song ID");
        }
    }
};
