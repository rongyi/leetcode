// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/
#include "xxx.hpp"

class Solution {
public:
  int minOperations(vector<int> &nums, vector<int> &numsDivide) {
    int g = numsDivide[0];
    for (auto &n : numsDivide) {
      g = gcd(g, n);
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() && nums[i] <= g; ++i) {
      if (g % nums[i] == 0) {
        return i;
      }
    }

    return -1;
  }
};
