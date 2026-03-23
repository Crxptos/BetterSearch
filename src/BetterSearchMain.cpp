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

        // Temporary: log results (UI handled separately)
        this->updateBetterSearchUI(results);

        // Keep original search
        LevelSearchLayer::onSearch(sender);
    }

    void updateBetterSearchUI(std::vector<std::string> results) {
        log::info("BetterSearch Results:");
        for (auto const& r : results) {
            log::info(" - {}", r);
        }
    }
};
