// http://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include "one.h"
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int first = 0;
    int last = nums.size();
    while (first != last) {
      const int mid = first + (last - first) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      // in a regular order list
      if (nums[first] <= nums[mid]) {
        if (nums[first] <= target && target < nums[mid]) {
          last = mid;
        } else {
          first = mid + 1;
        }
      } else {                  // in a non regular order
        if (nums[mid] < target && target <= nums[last - 1]) {
          first = mid + 1;
        } else {
          last = mid;
        }
      }
    }
    return -1;
  }
};
