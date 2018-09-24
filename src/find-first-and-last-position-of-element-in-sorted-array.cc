// http://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#include "one.h"
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int first = 0;
    int last = nums.size();
    while (first < last) {
      const int mid = first + (last - first) / 2;
      if (nums[mid] == target) {
        vector<int> ret;
        int i = mid - 1;
        while (i >= 0 && nums[i] == nums[mid]) {
          i--;
        }
        ret.push_back(i + 1);
        i = mid + 1;
        while (i < nums.size() && nums[i] == nums[mid]) {
          i++;
        }
        ret.push_back(i - 1);
        return ret;

      } else if (target > nums[mid]) {
        first = mid + 1;
      } else {
        last = mid;
      }
    }
    return vector<int>{-1, -1};
  }
};
