// https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/
#include "xxx.hpp"

class Solution {
public:
  int maxNumOfMarkedIndices(vector<int> &nums) {
    int sz = nums.size();
    int left = 0;
    int right = (sz + 1) / 2;
    if (sz < 2) {
      return 0;
    }
    int ret = 0;
    sort(nums.begin(), nums.end());
    while (right < sz) {
      if (2 * nums[left] <= nums[right]) {
        left++;
        ret += 2;
      }
      right++;
    }

    return ret;
  }
};
