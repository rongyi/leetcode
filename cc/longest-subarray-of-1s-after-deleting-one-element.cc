// http://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
#include "xxx.hpp"

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    // 统计每一个0前后出现的1的个数
    int cur_count = 0;
    int prev_count = 0;
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        cur_count++;
      } else {
        // 每一次遇到0都触发这个运算
        ret = max(ret, cur_count + prev_count);

        prev_count = cur_count;
        cur_count = 0;
      }
    }
    // 最后一次手动触发
    ret = max(ret, cur_count + prev_count);

    if (ret == nums.size()) {
      return ret - 1;
    }
    return ret;
  }
};
