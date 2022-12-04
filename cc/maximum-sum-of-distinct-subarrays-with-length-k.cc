// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
#include "xxx.hpp"

class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    int sz = nums.size();
    long long ret = 0;
    long long win_sum = 0;
    map<int, int> cnt;

    for (int i = 0; i < sz; ++i) {
      win_sum += nums[i];
      cnt[nums[i]]++;
      if (i >= k) {
        win_sum -= nums[i - k];
        cnt[nums[i - k]]--;
        if (cnt[nums[i - k]] == 0) {
          cnt.erase(nums[i - k]);
        }
      }
      if (cnt.size() == k) {
        ret = max(ret, win_sum);
      }
    }
    return ret;
  }
};
