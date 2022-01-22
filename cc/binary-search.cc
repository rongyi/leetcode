// http://leetcode.com/problems/binary-search/description/
#include "xxx.hpp"

class Solution {
public:
  int search(vector<int> &nums, int target) {
    const int n = nums.size();
    int i = 0;
    int j = n;
    while (i < j) {
      const int mid = i + (j - i) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        j = mid;
      } else {
        i = mid + 1;
      }
    }
    return -1;
  }
};
