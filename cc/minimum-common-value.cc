// https://leetcode.com/problems/minimum-common-value/
#include "xxx.hpp"

class Solution {
public:
  int getCommon(vector<int> &nums1, vector<int> &nums2) {
    int sz1 = nums1.size();
    int sz2 = nums2.size();
    for (int i = 0, j = 0; i < sz1 && j < sz2;) {
      if (nums1[i] == nums2[j]) {
        return nums1[i];
      } else if (nums1[i] < nums2[j]) {
        i++;
      } else {
        j++;
      }
    }

    return -1;
  }
};
