// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
#include "xxx.hpp"

class Solution {
public:
  int partitionArray(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    int ret = 0;
    for (int i = 0; i < sz;) {
      int j = i;
      for (; j < sz && nums[j] - nums[i] <= k; j++) {
        ;
      }
      i = j;
      ret++;
    }

    return ret;
  }
};
