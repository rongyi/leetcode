// http://leetcode.com/problems/get-the-maximum-score/description/
#include "xxx.hpp"

class Solution {
public:
  int maxSum(vector<int> &nums1, vector<int> &nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
    long long dp1 = 0;
    long long dp2 = 0;
    long long ret = 0;

    // So we apply two points solutions,
    // and always take the step in the smaller element.
    // clang-format off
    // dp1[i] = dp2[j] = max(dp1[i-1], dp2[j-1]) + nums1[i] with nums1[i] = nums2[j]
    // dp1[i] = dp1[i-1] + nums1[i] with nums1[i] < nums2[j]
    // dp2[j] = dp2[j-1] + nums2[j] with nums2[j] < nums1[i]
    // clang-format on
    for (int i = 0, j = 0; i < m || j < n;) {
      if (i < m && j < n && nums1[i] == nums2[j]) {
        dp1 = dp2 = max(dp1, dp2) + nums1[i];
        i++;
        j++;
      } else if (i < m && ((j < n && nums1[i] < nums2[j]) || j == n)) {
        dp1 += nums1[i++];
      } else {
        dp2 += nums2[j++];
      }
    }

    return max(dp1, dp2) % int(pow(10, 9) + 7);
  }
};
