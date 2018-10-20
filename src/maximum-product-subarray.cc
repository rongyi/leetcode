// http://leetcode.com/problems/maximum-product-subarray/description/
#include "one.h"

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    const int n = nums.size();
    if (n == 0) {
      return 0;
    }
    int ret = nums[0];
    int cur_max = nums[0];
    int cur_min = nums[0];

    for (int i = 1; i < n; ++i) {
      auto tmp_max = max3(nums[i], cur_max * nums[i], cur_min * nums[i]);
      auto tmp_min = min3(nums[i], cur_min * nums[i], cur_max * nums[i]);

      cur_max = tmp_max;
      cur_min = tmp_min;

      ret = max(tmp_max, ret);
    }

    return ret;
  }

private:
  int max3(int a, int b, int c) {
    if (a > b) {
      return max(a, c);
    }
    return max(b, c);
  }
  int min3(int a, int b, int c) {
    if (a < b) {
      return min(a, c);
    }
    return min(b, c);
  }
};
