// http://leetcode.com/problems/maximum-average-subarray-i/description/
#include "xxx.h"

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    // 1 <= k <= n <= 30,000.
    long long sum = accumulate(nums.begin(), nums.begin() + k, 0ll);
    double dk = (double)k;
    double avg = sum / dk;
    for (int i = k; i < nums.size(); i++) {
      sum += nums[i];
      sum -= nums[i - k];
      avg = max(avg, sum / dk);
    }

    return avg;
  }
};
