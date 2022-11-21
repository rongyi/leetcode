// https://leetcode.com/problems/minimum-cost-to-make-array-equal/
#include "xxx.hpp"

class Solution {
public:
  long long minCost(vector<int> &nums, vector<int> &cost) {
    int sz = nums.size();
    vector<long long> ids(sz, 0);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(),
         [&](int i, int j) { return nums[i] < nums[j]; });
    // choose each one as pivot, and calculate
    // the left side cost to reach this pivot
    vector<long long> costl(sz, 0);
    for (long long i = 0, csum = 0; i < sz - 1; ++i) {
      csum += cost[ids[i]];
      // we patched all value to cost[i]
      // so we need the total weight: csum
      // to patch another
      costl[i + 1] = costl[i] + csum * (nums[ids[i + 1]] - nums[ids[i]]);
    }

    long long ret = costl.back();
    // we dont't need to cache all value
    long long cur_cost = 0;
    for (long long j = sz - 1, csum = 0; j > 0; --j) {
      csum += cost[ids[j]];
      cur_cost += csum * (nums[ids[j]] - nums[ids[j - 1]]);
      ret = min(ret, cur_cost + costl[j - 1]);
    }

    return ret;
  }
};
