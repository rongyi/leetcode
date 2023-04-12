// http://leetcode.com/problems/maximum-product-subarray/description/
#include "xxx.hpp"

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int max_prod = nums[0];
    int min_prod = nums[0];
    int ret = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int tmp = max({nums[i], nums[i] * max_prod, nums[i] * min_prod});
      min_prod = min({nums[i], nums[i] * max_prod, nums[i] * min_prod});
      max_prod = tmp;
      ret = max(ret, max_prod);
    }

    return ret;
  }
};
