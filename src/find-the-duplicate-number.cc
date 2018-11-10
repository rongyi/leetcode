// http://leetcode.com/problems/find-the-duplicate-number/description/
#include "simpleone.h"

class Solution {
public:
  // There is only one duplicate number in the array, but it could be repeated more than once.
  int findDuplicate(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        return nums[i];
      }
    }
    return -1;
  }
};
