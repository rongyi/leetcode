// http://leetcode.com/problems/number-of-good-pairs/description/
#include "xxx.h"

class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    int ret = 0;

    unordered_map<int, int> count;
    for (auto &num : nums) {
      count[num]++;
    }
    for (auto &kv : count) {
      if (kv.second > 1) {
        ret += kv.second * (kv.second - 1) / 2;
      }
    }
    return ret;
  }
};
