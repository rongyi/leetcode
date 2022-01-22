// http://leetcode.com/problems/single-number/description/
#include "xxx.hpp"

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    auto ret = 0;
    for (auto i : nums) {
      ret ^= i;
    }

    return ret;
  }
};
