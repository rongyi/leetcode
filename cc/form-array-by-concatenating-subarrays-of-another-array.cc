// http://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/description/
#include "xxx.h"

class Solution {
public:
  // 按顺序排着即可
  bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
    int num_idx = 0;
    int grp_idx = 0;
    const int m = groups.size();
    const int n = nums.size();
    while (num_idx < n && grp_idx < m) {
      auto mached_count = 0;
      auto &cur_group = groups[grp_idx];
      while (num_idx + mached_count < n && mached_count < cur_group.size() &&
             nums[num_idx + mached_count] == cur_group[mached_count]) {
        mached_count++;
      }
      if (mached_count == cur_group.size()) {
        ++grp_idx;
        num_idx += mached_count;
      } else {
        num_idx++;
      }
    }

    return grp_idx == m;
  }
};
