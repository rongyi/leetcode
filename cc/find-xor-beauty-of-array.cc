// https://leetcode.com/problems/find-xor-beauty-of-array/
#include "xxx.hpp"

class Solution {
public:
  int xorBeauty(vector<int> &nums) {
    int ret = 0;
    for (auto &num: nums) {
      ret ^= num;
    }

    return ret;
  }
};
