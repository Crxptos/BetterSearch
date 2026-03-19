#include "FuzzyText.hpp"
#include <vector>
#include <algorithm>
#include <climits>

// 🔢 Levenshtein Distance
int levenshtein(const std::string& a, const std::string& b) {
    int m = a.size(), n = b.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;

            dp[i][j] = std::min({
                dp[i - 1][j] + 1,
                dp[i][j - 1] + 1,
                dp[i - 1][j - 1] + cost
            });
        }
    }

    return dp[m][n];
}

// 🔍 Find closest word
std::string findBestMatch(std::string input, std::vector<std::string> words) {
    int bestScore = INT_MAX;
    std::string bestMatch = input;

    // lowercase input
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    for (auto word : words) {
        std::string lowerWord = word;
        std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

        int dist = levenshtein(input, lowerWord);

        if (dist < bestScore) {
            bestScore = dist;
            bestMatch = word;
        }
    }

    return bestMatch;
}
