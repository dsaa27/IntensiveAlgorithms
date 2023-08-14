#pragma once

#include <vector>

// https://leetcode.com/problems/sort-an-array/
class Solution {
public:
  std::vector<int> sortArray(std::vector<int> &nums) {
        for (int i = 0; i < nums.size()-1; ++i) {
            for (int j = 0; j < nums.size()-1; ++j) {
                if (nums[j] > nums[j+1])
                    std::swap(nums[j], nums[j+1]);
            }
        }
        return nums;
  }
};