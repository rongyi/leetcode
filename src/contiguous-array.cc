// http://leetcode.com/problems/contiguous-array/description/
#include "xxx.h"

class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    int ctg_zero = 0;
    int ctg_one = 0;
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i]) {
        ctg_one++;
        ret = max(ret, min(ctg_one, ctg_zero));
        // ctg_zero = 0;
      } else {
        ctg_zero++;
        ret = max(ret, min(ctg_one, ctg_zero));
        // ctg_one = 0;
      }
    }

    return ret;
  }
};
