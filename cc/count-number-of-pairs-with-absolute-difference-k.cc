// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
#include "xxx.hpp"

class Solution {
public:
  int countKDifference(vector<int> &nums, int k) {
    map<int, int> cnt;
    for (auto &num : nums) {
      ++cnt[num];
    }
    int ret = 0;
    // remember to use reference
    for (auto &kv : cnt) {
      if (cnt.count(kv.first + k)) {
        ret += (kv.second * cnt[kv.first + k]);
      }
      if (cnt.count(kv.first - k)) {
        ret += (kv.second * cnt[kv.first - k]);
      }
      // don't use this value again
      kv.second = 0;
    }
    return ret;
  }
};
