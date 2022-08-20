// https://leetcode.com/problems/maximum-number-of-pairs-in-array/
#include "xxx.hpp"

class Solution {
public:
  vector<int> numberOfPairs(vector<int> &nums) {
    map<int, int> cnt;
    for (auto num : nums) {
      cnt[num]++;
    }

    vector<int> ret(2, 0);
    for (auto &kv : cnt) {
      ret[0] += kv.second / 2;
      ret[1] += kv.second % 2;
    }

    return ret;
  }
};
