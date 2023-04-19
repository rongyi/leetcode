// http://leetcode.com/problems/contains-duplicate-ii/description/
#include "xxx.hpp"

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    map<int, int> group;
    for (int i = 0; i < nums.size(); i++) {
      if (group.count(nums[i])) {
        if (i - group[nums[i]] <= k) {
          return true;
        }
      }
      group[nums[i]] = i;
    }

    return false;
  }
};
