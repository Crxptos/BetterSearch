#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(BetterSearchMain, LevelSearchLayer) {

    void onSearch(CCObject* sender) {
        std::string query = this->m_searchInput->getString();

        if (query.empty()) {
            LevelSearchLayer::onSearch(sender);
            return;
        }

        log::info("BetterSearch query: {}", query);

        // ✅ Fake results (safe, no web API)
        std::vector<std::string> results = {
            "Bloodbath",
            "Bloodlust",
            "Bloody",
            "Future Funk",
            "Sunset Sandstorm"
        };

        // 🔗 Send to BetterSearchLevels UI
        if (auto layer = typeinfo_cast<LevelSearchLayer*>(this)) {
            static_cast<BetterSearchLevels*>(layer)->updateBetterSearchUI(results);
        }

        // Keep original GD search
        LevelSearchLayer::onSearch(sender);
    }
};
