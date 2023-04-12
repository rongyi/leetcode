// http://leetcode.com/problems/maximum-gap/description/
#include "xxx.hpp"

class Solution {
public:
  int maximumGap(vector<int> &nums) {
    int sz = nums.size();
    int l = *min_element(nums.begin(), nums.end());
    int r = *max_element(nums.begin(), nums.end());

    if (sz < 2) {
      return 0;
    }
    int min_gap = max(1, (r - l) / (sz - 1));
    int bucket_nums = 1 + (r - l) / min_gap;
    vector<int> bmins(bucket_nums, numeric_limits<int>::max());
    vector<int> bmaxs(bucket_nums, numeric_limits<int>::min());

    for (int i = 0; i < sz; i++) {
      int idx = (nums[i] - l) / min_gap;
      bmins[idx] = min(bmins[idx], nums[i]);
      bmaxs[idx] = max(bmaxs[idx], nums[i]);
    }

    int ret = 0;
    int prev_max = l;
    for (int i = 0; i < bucket_nums; i++) {
      if (bmins[i] == numeric_limits<int>::max() ||
          bmaxs[i] == numeric_limits<int>::min()) {
        continue;
      }
      ret = max(ret, bmins[i] - prev_max);
      prev_max = bmaxs[i];
    }

    return ret;
  }
};
