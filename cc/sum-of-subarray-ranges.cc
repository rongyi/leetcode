// https://leetcode.com/problems/sum-of-subarray-ranges/
#include "xxx.hpp"

class Solution {
public:
  // O(n^2) can pass
  long long subArrayRanges(vector<int> &nums) {
    int sz = nums.size();
    long long sum = 0;

    for (int i = 0; i < sz; ++i) {
      int cur_max = nums[i];
      int cur_min = nums[i];
      for (int j = i + 1; j < sz; ++j) {
        cur_max = max(cur_max, nums[j]);
        cur_min = min(cur_min, nums[j]);
        sum += (cur_max - cur_min);
      }
    }

    return sum;
  }
};
