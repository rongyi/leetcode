// http://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/
#include "xxx.h"

class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    // left sum -> num count
    unordered_map<int, int> left;
    left[0] = 0;
    for (int i = 0, cur_sum = 0; i < nums.size() && cur_sum <= x; ++i) {
      cur_sum += nums[i];
      left[cur_sum] = i + 1;
    }

    int ret = numeric_limits<int>::max();
    if (left.count(x)) {
      ret = min(ret, left[x]);
    }

    for (int i = nums.size() - 1, cur_sum = 0; i >= 0 && cur_sum <= x; --i) {
      cur_sum += nums[i];

      auto it = left.find(x - cur_sum);
      // 不重叠
      if (it != left.end() && it->second <= i) {
        ret = min(ret, it->second + int(nums.size() - i));
      }
    }

    if (ret == numeric_limits<int>::max()) {
      return -1;
    }

    return ret;
  }
};
