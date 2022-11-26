// https://leetcode.com/problems/destroy-sequential-targets/
#include "xxx.hpp"

class Solution {
public:
  int destroyTargets(vector<int> &nums, int space) {
    map<int, int> cnt;
    int max_cnt = 0;
    for (auto &num : nums) {
      auto key = num % space;
      cnt[key]++;
      if (cnt[key] > max_cnt) {
        max_cnt = cnt[key];
      }
    }
    int ret = numeric_limits<int>::max();
    for (auto &num : nums) {
      if (cnt[num % space] == max_cnt) {
        ret = min(ret, num);
      }
    }
    return ret;
  }
};
