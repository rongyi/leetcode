// http://leetcode.com/problems/missing-number/description/
#include "simpleone.h"

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    const int n = nums.size();
    return n * (n + 1) / 2  - accumulate(nums.begin(), nums.end(), 0);
  }
};
