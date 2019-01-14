// http://leetcode.com/problems/leetcode/3sum-closest/description/
#include "xxx.h"

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int ret = 0;
    int min_gap = numeric_limits<int>::max();

    sort(nums.begin(), nums.end());
    const int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      int j = i + 1;
      int k = n - 1;
      while (j < k) {
        const int cur = nums[i] + nums[j] + nums[k];
        const int cur_gap = abs(cur - target);
        if (cur_gap < min_gap) {
          ret = cur;
          min_gap = cur_gap;
        }
        if (cur < target) {
          ++j;
        } else {
          --k;
        }
      }
    }


    return ret;
  }
};
