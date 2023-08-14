#pragma once

#include <string>

// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        std::vector<char> brackets;
        for (const auto ch : s) {
            if (ch == ')') {
                if (brackets.empty())
                    return false;
                brackets.pop_back();
            } else {
                brackets.push_back(' ');
            }
        }
        return brackets.empty();
    }
};
