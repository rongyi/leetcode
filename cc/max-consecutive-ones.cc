// http://leetcode.com/problems/max-consecutive-ones/description/
#include "xxx.hpp"

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int ret = 0;
    int count = 0;
    for (auto i : nums) {
      if (i == 1) {
        count++;
        ret = max(ret, count);
      } else {
        count = 0;
      }
    }

    return ret;
  }
};
