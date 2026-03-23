#include "FuzzyText.hpp"

#include <algorithm>
#include <string>

int FuzzyText::levenshteinDistance(const std::string& s1, const std::string& s2) {
    const size_t len1 = s1.size();
    const size_t len2 = s2.size();

    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1));

    for (size_t i = 0; i <= len1; ++i) dp[i][0] = i;
    for (size_t j = 0; j <= len2; ++j) dp[0][j] = j;

    for (size_t i = 1; i <= len1; ++i) {
        for (size_t j = 1; j <= len2; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;

            dp[i][j] = std::min({
                dp[i - 1][j] + 1,      // deletion
                dp[i][j - 1] + 1,      // insertion
                dp[i - 1][j - 1] + cost // substitution
            });
        }
    }

    return dp[len1][len2];
}

int FuzzyText::score(const std::string& query, const std::string& text) {
    if (query.empty() || text.empty()) return 0;

    int distance = levenshteinDistance(query, text);

    int maxLen = std::max(query.size(), text.size());
    if (maxLen == 0) return 0;

    // Convert distance → similarity score (0–100)
    int similarity = static_cast<int>(
        (1.0 - (double)distance / maxLen) * 100
    );

    return std::max(0, similarity);
}

bool FuzzyText::matches(const std::string& query, const std::string& text, int threshold) {
    return score(query, text) >= threshold;
}
