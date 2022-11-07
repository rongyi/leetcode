// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
#include "xxx.hpp"

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    // and will make number smaller
    // so find the maximum and just return
    int max_num = *max_element(nums.begin(), nums.end());
    int sz = nums.size();
    int ret = 1;
    for (int i = 0; i < sz;) {
      if (nums[i] != max_num) {
        i++;
      } else {
        // we meet a max_num, expand
        int j = i + 1;
        for (; j < sz && nums[j] == nums[j - 1]; ++j) {
        }
        ret = max(ret, j - i);
        i = j;
      }
    }
    return ret;
  }
};
