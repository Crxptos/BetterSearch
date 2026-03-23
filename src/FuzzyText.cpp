#include "FuzzyText.hpp"
#include <algorithm>

int fuzzyScore(const std::string& a, const std::string& b) {
    int score = 0;

    for (char c : a) {
        if (b.find(c) != std::string::npos) {
            score++;
        }
    }

    return score;
}

std::vector<std::string> fuzzySort(
    const std::vector<std::string>& list,
    const std::string& query
) {
    auto result = list;

    std::sort(result.begin(), result.end(), [&](const std::string& lhs, const std::string& rhs) {
        return fuzzyScore(lhs, query) > fuzzyScore(rhs, query);
    });

    return result;
}
