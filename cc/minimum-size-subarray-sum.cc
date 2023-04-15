// http://leetcode.com/problems/leetcode/minimum-size-subarray-sum/description/
#include "xxx.hpp"

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int sum = 0;
    int sz = nums.size();
    int ret = numeric_limits<int>::max();
    for (int j = 0, i = 0; j < sz; j++) {
      // right expand
      sum += nums[j];
      // left shrink
      while (sum >= target) {
        ret = min(ret, j - i + 1);
        sum -= nums[i++];
      }
    }

    if (ret == numeric_limits<int>::max()) {
      return 0;
    }
    return ret;
  }
};
