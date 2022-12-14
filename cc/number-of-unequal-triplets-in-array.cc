// https://leetcode.com/problems/number-of-unequal-triplets-in-array/
#include "xxx.hpp"

class Solution {
public:
  int unequalTriplets(vector<int> &nums) {
    map<int, int> cnt;
    for (auto &num : nums) {
      cnt[num]++;
    }
    int ret = 0;
    for (auto &kv1 : cnt) {
      for (auto &kv2 : cnt) {
        for (auto &kv3 : cnt) {
          if (kv1.first < kv2.first && kv2.first < kv3.first) {
            ret += kv1.second * kv2.second * kv3.second;
          }
        }
      }
    }

    return ret;
  }
};
