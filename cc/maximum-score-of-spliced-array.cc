// https://leetcode.com/problems/maximum-score-of-spliced-array/
#include "xxx.hpp"

class Solution {
public:
  int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

    int ret = max(sum1, sum2);

    // swap to make sum1 bigger
    int ch1 = 0;
    int maxch1 = 0;
    // swap to make sum2 bigger
    int ch2 = 0;
    int maxch2 = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      ch1 += (nums2[i] - nums1[i]);
      ch2 += (nums1[i] - nums2[i]);

      maxch1 = max(maxch1, ch1);
      maxch2 = max(maxch2, ch2);

      if (ch1 < 0) {
        ch1 = 0;
      }
      if (ch2 < 0) {
        ch2 = 0;
      }
    }

    ret = max(ret, sum1 + maxch1);
    ret = max(ret, sum2 + maxch2);

    return ret;
  }
};
