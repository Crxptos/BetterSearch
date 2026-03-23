class $modify(BetterSearchMain, LevelSearchLayer) {

    void onSearch(CCObject* sender) {
        std::string query = this->m_searchInput->getString();

        if (query.empty()) {
            LevelSearchLayer::onSearch(sender);
            return;
        }

        std::vector<std::string> results = {
            "Bloodbath",
            "Bloodlust",
            "Bloody"
        };

        this->updateBetterSearchUI(results);

        LevelSearchLayer::onSearch(sender);
    }

    void updateBetterSearchUI(std::vector<std::string> results) {
        for (auto const& r : results) {
            log::info("Result: {}", r);
        }
    }
};
