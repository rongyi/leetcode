// http://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/
#include "xxx.h"

class Solution {
public:
  int reductionOperations(vector<int> &nums) {
    int ret = 0;
    int sz = nums.size();
    // 2 1 4 4 5 7 7 7
    // 7 7 7 --> 3
    // 5 7 7 7 -> 4
    // 4 4 5 7 7 7 -> 6
    // ...
    sort(nums.begin(), nums.end());
    for (int i = sz - 1; i > 0; --i) {
      if (nums[i - 1] != nums[i]) {
        ret += sz - i;
      }
    }

    return ret;
  }
};
