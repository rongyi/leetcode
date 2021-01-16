// http://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/description/
#include "xxx.h"

class Solution {
public:
  int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests) {
    vector<int> count(nums.size(), 0);
    for (auto &r : requests) {
      count[r[0]] += 1;
      if (r[1] + 1 < count.size()) {
        count[r[1] + 1] -= 1;
      }
    }
    for (int i = 1; i < count.size(); ++i) {
      count[i] += count[i - 1];
    }
    sort(nums.begin(), nums.end());
    sort(count.begin(), count.end());
    long ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      ret = (ret + (long)nums[i] * count[i]) % (int)(1e9 + 7);
    }

    return ret;
  }
};
