// https://leetcode.com/problems/maximum-xor-after-operations/
#include "xxx.hpp"

class Solution {
public:
  int maximumXOR(vector<int> &nums) {
    int ret = 0;

    // keep every single bits
    for (auto &num : nums) {
      for (int i = 0; i < 31; ++i) {
        ret |= (num & (1 << i));
      }
    }

    return ret;
  }
};
