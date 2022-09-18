// https://leetcode.com/problems/find-subarrays-with-equal-sum/
#include "xxx.hpp"

class Solution {
public:
  bool findSubarrays(vector<int> &nums) {
    int sz = nums.size();
    long long sum = 0;
    map<long long, int> cnt;

    for (int i = 0; i < sz; ++i) {
      sum += nums[i];
      if (i >= 2) {
        sum -= nums[i - 2];
      }
      if (i >= 1) {
        cnt[sum]++;
        if (cnt[sum] == 2) {
          return true;
        }
      }
    }

    return false;
  }
};
