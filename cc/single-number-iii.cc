// http://leetcode.com/problems/single-number-iii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    auto accxor = [](vector<int> &n) -> int {
      auto ret = 0;
      for (auto &i : n) {
        ret ^= i;
      }
      return ret;
    };
    // 1. xor them all!
    int split = accxor(nums);
    int i = 0;
    for (; i < 32; i++) {
      if ((split & (1 << i)) != 0) {
        break;
      }
    }
    // we get the first postion which two number are different
    vector<int> g1;
    vector<int> g2;
    for (auto &num : nums) {
      if ((num & (1 << i)) != 0) {
        g1.push_back(num);
      } else {
        g2.push_back(num);
      }
    }

    return {accxor(g1), accxor(g2)};
  }
};
