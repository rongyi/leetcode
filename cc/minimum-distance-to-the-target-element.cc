// http://leetcode.com/problems/minimum-distance-to-the-target-element/description/
#include "xxx.h"

class Solution {
public:
  int getMinDistance(vector<int> &nums, int target, int start) {
    int d = numeric_limits<int>::max();
    for (int i = start; i < nums.size(); ++i) {
      if (nums[i] == target) {
        d = min(d, i - start);
        break;
      }
    }
    for (int i = start; i >= 0; --i) {
      if (nums[i] == target) {
        d = min(d, start - i);
        break;
      }
    }

    return d;
  }
};
