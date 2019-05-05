// http://leetcode.com/problems/subarray-product-less-than-k/description/
#include "xxx.h"

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k == 0) {
      return 0;
    }
    int ret = 0;
    int multi = 1;
    for (int i = 0, j = 0; j < nums.size(); j++) {
      multi *= nums[j];
      while (i <= j && multi >= k) {
        multi /= nums[i++];
      }
      ret += j - i + 1;
    }
    return ret;
  }
};
