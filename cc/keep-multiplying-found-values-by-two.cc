// https://leetcode.com/problems/keep-multiplying-found-values-by-two/
#include "xxx.hpp"

class Solution {
public:
  int findFinalValue(vector<int> &nums, int original) {
    sort(nums.begin(), nums.end());

    for (auto &n : nums) {
      if (n == original) {
        original *= 2;
      }
    }

    return original;
  }
};
