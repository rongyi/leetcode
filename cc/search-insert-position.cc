// http://leetcode.com/problems/search-insert-position/description/
#include "xxx.hpp"
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  }
};
