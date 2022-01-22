// http://leetcode.com/problems/merge-sorted-array/description/
#include "xxx.hpp"

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    auto cp1 = nums1;

    auto idx = 0;
    int i = 0;
    int j = 0;
    for (; i < m && j < n;) {
      if (cp1[i] < nums2[j]) {
        nums1[idx++] = cp1[i];
        i++;
      } else {
        nums1[idx++] = nums2[j];
        j++;
      }
    }
    if (i < m) {
      for (; i < m; ++i) {
        nums1[idx++] = cp1[i];
      }
    }
    if (j < n) {
      for (; j < n; ++j) {
        nums1[idx++] = nums2[j];
      }
    }
  }
};
