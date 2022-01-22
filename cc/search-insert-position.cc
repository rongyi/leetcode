// http://leetcode.com/problems/search-insert-position/description/
#include "xxx.hpp"
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int first = 0;
    int last = nums.size();
    while (first < last) {
      const int mid = first + (last - first) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        last = mid;
      } else {
        first = mid + 1;
      }
    }
    // now we have first == last
    return first;
  }
};
