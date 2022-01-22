// http://leetcode.com/problems/parallel-courses-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int minNumberOfSemesters(int n, vector<vector<int>> &dependencies, int k) {
    vector<int> pre(n, 0);
    // 1 -> 2
    // 2的先导课程是1
    // 记录每门课的先导课程的mask
    for (auto &dep : dependencies) {
      pre[dep[1] - 1] |= 1 << (dep[0] - 1);
    }

    // 找的是最小的
    vector<int> dp(1 << n, n);
    dp[0] = 0;
    // i是当前的学习课程的一个集合，哪门课学了就是1,没学就是0
    for (int i = 0; i < (1 << n); ++i) {
      int can_study = 0;
      // 这门课的先导课程也包含在当前i中，也就是学习过了
      for (int j = 0; j < n; ++j) {
        // i是超集包含了依赖课程
        if ((i & pre[j]) == pre[j]) {
          can_study |= (1 << j);
        }
      }
      // 去除了已经学习的课程
      can_study &= ~i;

      for (int s = can_study; s; s = (s - 1) & can_study) {
        if (count_bit(s) <= k) {
          dp[i | s] = min(dp[i | s], dp[i] + 1);
        }
      }
    } // end for

    return dp.back();
  }

private:
  int count_bit(int mask) {
    int ret = 0;
    while (mask) {
      ++ret;
      mask &= (mask - 1);
    }

    return ret;
  }
};
