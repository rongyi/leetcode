// http://leetcode.com/problems/array-partition-i/description/
#include "xxx.h"

class Solution {
public:
  // nums size is even
  int arrayPairSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int ret = 0;
    // we make small num together to keep
    // great number to add to ret;
    for (int i = 0; i < nums.size(); i += 2) {
      ret += min(nums[i], nums[i + 1]);
    }
    return ret;
  }
};
