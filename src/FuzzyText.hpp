#pragma once
#include <string>
#include <vector>

// 🔢 Distance between two words
int levenshtein(const std::string& a, const std::string& b);

// 🔍 Find closest match from a list
std::string findBestMatch(std::string input, std::vector<std::string> words);
