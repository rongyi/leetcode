// https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
#include "one.h"
class Solution {
public:
  // return the k-th smallest distance among all the pairs
  int smallestDistancePair(vector<int> &nums, int k) {
    // 总共值区间在一百万以内，那就创建这么多桶，
    // 然后差值往桶里丢，统计出来之后
    // 从最小的差值往后找
    const int n = 1000000;
    vector<int> cnt(n, 0);
    const int len = nums.size();
    for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j < len; ++j) {
        ++cnt[abs(nums[i] - nums[j])];
      }
    }
    for (int i = 0; i < n; i++) {
      if (cnt[i] >= k) {
        return i;
      }
      // 精彩
      k -= cnt[i];
    }
    return -1;
  }
};
