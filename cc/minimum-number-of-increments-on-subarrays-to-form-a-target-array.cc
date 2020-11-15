// http://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/
#include "xxx.h"

class Solution {
public:
  // 连不到一起的时候就不能一起减了，连不到一起的成立条件就是
  // 出现了递增的情况
  int minNumberOperations(vector<int> &target) {
    int ret = target[0];
    for (int i = 1; i < target.size(); ++i) {
      ret += max(0, target[i] - target[i - 1]);
    }

    return ret;
  }
};
