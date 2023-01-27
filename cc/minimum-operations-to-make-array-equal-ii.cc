// https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/
#include "xxx.hpp"

class Solution {
public:
  long long minOperations(vector<int> &nums1, vector<int> &nums2, int k) {
    int sz = nums1.size();
    long long above = 0;
    long long below = 0;
    if (k == 0) {
      for (int i = 0; i < sz; ++i) {
        if (nums1[i] != nums2[i]) {
          return -1;
        }
      }
      return 0;
    }

    for (int i = 0; i < sz; ++i) {
      int diff = nums1[i] - nums2[i];
      if ((diff % k) != 0) {
        return -1;
      }
      if (diff > 0) {
        above += (diff / k);
      } else if (diff < 0) {
        below += (-diff / k);
      }
    }

    if (above != below) {
      return -1;
    }
    return above;
  }
};
