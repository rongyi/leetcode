// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

#include "xxx.hpp"
class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (arr[mid] < arr[mid + 1]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }
};
