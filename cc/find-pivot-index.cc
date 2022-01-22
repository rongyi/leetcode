// http://leetcode.com/problems/find-pivot-index/description/
#include "xxx.hpp"

class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    // 用1到n的空间
    const int n = nums.size();
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + nums[i];
    }
    for (int i = 1; i <= n; i++) {
      long long left = sum[i - 1];
      long long right = sum[n] - sum[i];
      if (left == right) {
        return i - 1;
      }
    }
    return -1;
  }
};
