// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/
#include "xxx.hpp"

class Solution {
public:
  int countPairs(vector<int> &nums, int k) {
    map<int, vector<int>> group;
    for (int i = 0; i < nums.size(); ++i) {
      group[nums[i]].push_back(i);
    }
    int ret = 0;
    for (auto &kv : group) {
      auto &lst = kv.second;
      int sz = lst.size();
      if (sz < 2) {
        continue;
      }
      int prev = 0;
      for (int i = 0; i < sz; ++i) {
        for (int j = i + 1; j < sz; ++j) {
          auto m = lst[i] * lst[j];
          if (m % k == 0) {
            ++ret;
          }
        }
      }
    }
    return ret;
  }
};
