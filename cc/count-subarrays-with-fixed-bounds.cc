// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
#include "xxx.hpp"

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    int start = 0;
    int min_index = -1;
    int max_index = -1;
    long long ret = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < minK || nums[i] > maxK) {
        min_index = -1;
        max_index = -1;
        start = i + 1;
      }
      if (nums[i] == minK) {
        min_index = i;
      }
      if (nums[i] == maxK) {
        max_index = i;
      }
      if (min_index != -1 && max_index != -1) {
        ret += (min(min_index, max_index) - start + 1);
      }
    }

    return ret;
  }
};
