// https://leetcode.com/problems/count-subarrays-with-median-k/
#include "xxx.hpp"

class Solution {
public:
  int countSubarrays(vector<int> &nums, int k) {
    map<int, int> cnt;
    int idx = find(nums.begin(), nums.end(), k) - nums.begin();
    for (int i = idx, cur = 0; i < nums.size(); ++i) {
      if (nums[i] < k) {
        cur--;
      } else if (nums[i] > k) {
        cur++;
      }
      cnt[cur]++;
    }
    int ret = 0;
    for (int i = idx, cur = 0; i >= 0; --i) {
      if (nums[i] < k) {
        cur--;
      } else if (nums[i] > k) {
        cur++;
      }
      ret += cnt[-cur] + cnt[-cur + 1];
    }

    return ret;
  }
};
