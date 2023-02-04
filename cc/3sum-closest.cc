// https://leetcode.com/problems/3sum-closest/
#include "xxx.hpp"

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    int ret = -1;
    int min_gap = numeric_limits<int>::max();
    for (int i = 0; i < sz - 1; ++i) {
      int j = i + 1;
      int k = sz - 1;
      while (j < k) {
        int cur_sum = nums[i] + nums[j] + nums[k];
        int cur_gap = abs(cur_sum - target);
        if (cur_gap < min_gap) {
          min_gap = cur_gap;
          ret = cur_sum;
        }
        if (cur_sum < target) {
          j++;
        } else {
          k--;
        }
      }
    }
    return ret;
  }
};
