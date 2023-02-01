// http://leetcode.com/problems/median-of-two-sorted-arrays/description/
#include "xxx.hpp"

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());
    int sz = nums1.size();
    if (sz & 1) {
      return nums1[sz / 2];
    }
    return ((double)nums1[sz / 2 - 1] + (double)nums1[sz / 2]) / 2.0;
  }
};
