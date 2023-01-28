// https://leetcode.com/problems/minimum-cost-to-split-an-array/
#include "xxx.hpp"

class Solution {
public:
  int minCost(vector<int> &nums, int k) {
    map<int, int> cnt;
    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      auto it = cnt.find(nums[i]);
      if (it == cnt.end()) {
        it = cnt.insert({nums[i], cnt.size()}).first;
      }
      // nums[i] become the uniq number count
      // [1, 3, 3, 3, 4, 4]
      // [1, 2, 2, 2, 3, 3]
      nums[i] = it->second;
    }

    int dp[1001] = {};
    for (int i = 0; i < sz; ++i) {
      int cnt[1001] = {};
      int trim = 0;

      for (int j = i; j < sz; ++j) {
        if (++cnt[nums[j]] > 1) {
          // init add2, then add 1
          trim += cnt[nums[j]] == 2 ? 2 : 1;
        }
        dp[j + 1] = min(dp[j + 1] ? dp[j + 1] : numeric_limits<int>::max(),
                        dp[i] + k + trim);
      }
    }

    return dp[sz];
  }
};
