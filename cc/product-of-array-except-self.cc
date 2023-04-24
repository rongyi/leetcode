// http://leetcode.com/problems/product-of-array-except-self/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int sz = nums.size();
    vector<int> ret(sz, 1);
    int lacc = nums[0];
    int racc = nums[sz - 1];

    for (int i = 1; i < sz; i++) {
      ret[i] *= lacc;
      lacc *= nums[i];
    }
    for (int i = sz - 2; i >= 0; i--) {
      ret[i] *= racc;
      racc *= nums[i];
    }

    return ret;
  }
};

