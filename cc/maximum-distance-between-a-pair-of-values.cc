// http://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/
#include "xxx.h"

class Solution {
public:
  int maxDistance(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    // the minums num in nums1 is still larger than the biggest num in nums2
    // so there's no valid choice
    int i = 0;
    int j = 0;
    int ret = 0;

    while (i < m && j < n) {
      if (nums1[i] > nums2[j]) {
        ++i;
      } else {
        ret = max(ret, j - i);
        j++;
      }
    }

    return ret;
  }
};
