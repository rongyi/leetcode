// http://leetcode.com/problems/check-if-it-is-a-good-array/description/
#include "xxx.hpp"

class Solution {
public:
  bool isGoodArray(vector<int> &nums) {
    auto gcd = nums[0];

    for (auto n : nums) {
      gcd = __gcd(gcd, n);
    }

    return gcd == 1;
  }
};
