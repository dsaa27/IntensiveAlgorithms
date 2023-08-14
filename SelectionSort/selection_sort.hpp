#pragma once

#include <vector>

// https://leetcode.com/problems/sort-an-array/
class Solution {
public:
  std::vector<int> sortArray(std::vector<int> &nums) {
    for (auto it = nums.begin(); it !=  nums.end(); ++it) {
      const auto minIt = std::min_element(it, nums.end());
      std::swap(*it, *minIt);
    }
    return nums;
  }
};
