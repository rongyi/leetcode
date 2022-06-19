// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
#include "xxx.hpp"

class Solution {
public:
  long long countSubarrays(vector<int> &nums, long long k) {
    long long ret = 0;

    long long sum = 0;
    for (int i = 0, j = 0; i < nums.size(); ++i) {
      sum += nums[i];
      while (sum * (i - j + 1) >= k) {
        sum -= nums[j++];
      }

      ret += (i - j + 1);
    }

    return ret;
  }
};
