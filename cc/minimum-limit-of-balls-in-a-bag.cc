// http://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/
#include "xxx.h"

class Solution {
public:
  int minimumSize(vector<int> &nums, int maxOperations) {
    int l = 1;
    int r = 1e9;
    while (l < r) {
      auto m = (l + r) / 2;
      int count = 0;
      for (auto &n : nums) {
        // 这个公式可以： 分成最大份为m的话需要的次数
        // 分x次， 最大值为m的值区间为： [x * m + 1, x * m + m]
        count += (n - 1) / m;
      }
      // 还可以再放放， m再小一点？
      if (count <= maxOperations) {
        r = m;
      } else {
        // 收缩
        l = m + 1;
      }
    }
    return l;
  }
};
