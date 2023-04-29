// http://leetcode.com/problems/find-the-duplicate-number/description/
#include "xxx.hpp"

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    // same as linked list cycle
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }
    fast = 0;
    while (slow != fast) {
      fast = nums[fast];
      slow = nums[slow];
    }

    return slow;
  }
};
