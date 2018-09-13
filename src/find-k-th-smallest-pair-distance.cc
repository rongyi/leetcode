// https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
#include "one.h"
class Solution {
public:
  // return the k-th smallest distance among all the pairs
  int smallestDistancePair(vector<int> &nums, int k) {
    const int n = 1000000;
    // 代表差绝对值为i的个数
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
      k -= cnt[i];
    }
    return -1;
  }
};
