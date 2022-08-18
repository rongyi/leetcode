// https://leetcode.com/problems/minimum-sum-of-squared-difference/
#include "xxx.hpp"

class Solution {
public:
  long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1,
                             int k2) {
    int n = nums1.size();
    vector<int> diff(n, 0);
    for (int i = 0; i < n; ++i) {
      diff[i] = abs(nums1[i] - nums2[i]);
    }
    int max_diff = *max_element(diff.begin(), diff.end());
    vector<int> bucket(max_diff + 1, 0);
    for (int i = 0; i < n; ++i) {
      // count diff number
      bucket[diff[i]]++;
    }
    int k = k1 + k2;

    for (int i = max_diff; i >= 0 && k; --i) {
      int cut = min(bucket[i], k);
      k -= cut;
      bucket[i] -= cut;

      // what this?
      // when you decrement cut nums of current bucket, all there diff is shrink
      // by 1, and their diff drop in its left range
      if (i > 0) {
        bucket[i - 1] += cut;
      }
    }
    long long ret = 0;
    for (int i = 0; i < max_diff + 1; i++) {
      ret += (long long)i * i * bucket[i];
    }

    return ret;
  }
};
