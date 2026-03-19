#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/utils/web.hpp>

using namespace geode::prelude;

class $modify(BetterSearchLayer, LevelSearchLayer) {

    void onSearch(CCObject* sender) {
        std::string query = this->m_searchInput->getString();

        if (query.empty()) {
            LevelSearchLayer::onSearch(sender);
            return;
        }

        log::info("BetterSearch query: {}", query);

        // 🔍 Optional: Web request (can expand later)
        std::string url = "https://gdbrowser.com/api/search/" + query;

        web::AsyncWebRequest()
            .fetch(url)
            .then([this, query](auto* res) {
                log::info("Received response");

                // 👉 For now: use dummy results
                std::vector<std::string> results = {
                    "Bloodbath",
                    "Bloodlust",
                    "Bloody",
                    "Future Funk",
                    "Sunset Sandstorm"
                };

                // 🔗 Send to UI (implemented in BetterSearchLevels.cpp)
                this->updateBetterSearchUI(results);
            })
            .expect([](auto* err) {
                log::error("Search failed");
            });

        // Keep original GD search
        LevelSearchLayer::onSearch(sender);
    }

    // 🔗 This connects to your UI system
    void updateBetterSearchUI(std::vector<std::string> results) {
        // This function will be defined in BetterSearchLevels.cpp
        // (same modified class)
    }
};
