// http://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/description/
#include "xxx.hpp"

class Solution {
public:
  // 主要就是subarray的
  int closestToTarget(vector<int> &arr, int target) {
    int ret = numeric_limits<int>::max();
    const int n = arr.size();
    // and_nums[i] i开始位置的与的uniq的那些数字
    // contains AND values of subarrays starting from ith index
    set<int> and_nums[n];
    and_nums[n - 1].insert(arr[n - 1]);

    for (int i = n - 2; i >= 0; --i) {
      // 首先是当前的这个值
      and_nums[i].insert(arr[i]);
      // 其次是跟之前的and操作的值
      for (auto &next_num : and_nums[i + 1]) {
        and_nums[i].insert(arr[i] & next_num);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (auto &num : and_nums[i]) {
        ret = min(ret, abs(num - target));
      }
    }

    return ret;
  }
};
