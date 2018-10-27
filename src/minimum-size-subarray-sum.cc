// http://leetcode.com/problems/leetcode/minimum-size-subarray-sum/description/
#include "simpleone.h"

class Solution {
public:
  int minSubArrayLen(int s, vector<int> &nums) {
    int ret = numeric_limits<int>::max();
    int sum = 0;
    int left = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      // shrink the left
      if (sum >= s) {
        while(left <= i && sum >= s) {
          ret = min(ret, i - left + 1);
          sum -= nums[left++];
        }
      }
    }

    return ret == numeric_limits<int>::max() ? 0 : ret;
  }
};
