// http://leetcode.com/problems/product-of-array-except-self/description/
#include "simpleone.h"

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    const int n = nums.size();
    vector<long long> left(n, 0);
    left[0] = 1;
    for (int i = 1; i < n; i++) {
      left[i] = left[i - 1] * nums[i - 1];
    }
    vector<long long> right(n, 0);
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
      right[i] = right[i + 1] * nums[i + 1];
    }
    vector<int> ret(n, 0);
    for (int i = 0; i < n; i++) {
      ret[i] = left[i] * right[i];
    }

    return ret;
  }
};
