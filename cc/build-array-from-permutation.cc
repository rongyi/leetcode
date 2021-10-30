// https://leetcode.com/problems/build-array-from-permutation/
#include "xxx.h"

class Solution {
public:
  //  vector<int> buildArray(vector<int> &nums) {
  //    int sz = nums.size();
  //    vector<int> ret(sz, 0);
  //    for (int i = 0; i < sz; ++i) {
  //      ret[i] = nums[nums[i]];
  //    }
  //
  //    return ret;
  //  }

  vector<int> buildArray(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      // to % n to get the real nums[i]
      nums[i] = nums[i] + n * (nums[nums[i]] % n);
    }
    for (int i = 0; i < n; ++i) {
      nums[i] /= n; // get rid of the original nums[i]
    }
    return nums;
  }
};
