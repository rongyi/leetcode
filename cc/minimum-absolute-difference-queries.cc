// http://leetcode.com/problems/minimum-absolute-difference-queries/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
    int sz = nums.size();
    vector<int> byvalue[101];

    // value range is very important! shit
    for (int i = 0; i < sz; ++i) {
      byvalue[nums[i]].push_back(i);
    }

    // fast path
    if (byvalue[nums.front()].size() == nums.size()) {
      return vector<int>(queries.size(), -1);
    }
    vector<int> ret(queries.size());

    for (int i = 0; i < queries.size(); ++i) {
      int prev = -1;
      // or 101 is the max value which is a bit wield
      int min_diff = 101;

      for (int vi = 1; vi <= 100; ++vi) {
        // without this reference will OOM
        auto &cur_idxs = byvalue[vi];
        // find some value in query range
        auto it = lower_bound(cur_idxs.begin(), cur_idxs.end(), queries[i][0]);
        // not valid range
        if (it == cur_idxs.end() || *it > queries[i][1]) {
          continue;
        }

        if (prev != -1) {
          min_diff = min(min_diff, vi - prev);
        }

        prev = vi;
      }

      if (min_diff == 101) {
        ret[i] = -1;
      } else {
        ret[i] = min_diff;
      }
    }

    return ret;
  }
};
