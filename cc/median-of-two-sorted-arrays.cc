// http://leetcode.com/problems/median-of-two-sorted-arrays/description/
#include "xxx.hpp"

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());
    auto n = nums1.size();
    if (n % 2 == 1) {
      return nums1[n / 2];
    }
    return ((double)(nums1[n / 2]) + (double)(nums1[n / 2 - 1]))/ 2;
  }
};
