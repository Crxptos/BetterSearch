#pragma once

#include <string>
#include <vector>

class FuzzyText {
public:
    static int levenshteinDistance(const std::string& s1, const std::string& s2);
    static int score(const std::string& query, const std::string& text);
    static bool matches(const std::string& query, const std::string& text, int threshold = 70);
};
