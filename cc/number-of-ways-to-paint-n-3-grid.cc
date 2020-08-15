// http://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/
#include "xxx.h"

class Solution {
public:
  // 第一种情况：我们的当前行由两种颜色构成也就是左图所示，那么新加的行要么是两种颜色，要么是三种颜色；

  // 如果新加的行是两种颜色组成的，那么只有三种情况；
  // 如果新加的行是三种颜色组成的，那么只有两种情况。
  // 第二种情况：我们的当前行由三种颜色构成也就是右图所示，那么新加的行要么是两种颜色，要么是三种颜色；

  // 如果新加的行是两种颜色组成的，那么只有两种情况；
  // 如果新加的行是三种颜色组成的，那么只有两种情况。
  int numOfWays(int n) {
    if (n == 1) {
      return 12;
    }
    const int mod = 1e9 + 7;
    vector<long> c2(n + 1, 0);
    vector<long> c3(n + 1, 0);
    c2[1] = 6;
    c3[1] = 6;

    int ret = 0;
    for (int i = 2; i <= n; ++i) {
      c2[i] = (2 * c3[i - 1] + 2 * c2[i - 1]) % mod;
      c3[i] = (3 * c3[i - 1] + 2 * c2[i - 1]) % mod;
    }
    ret = (c2.back() % mod + c3.back() % mod) % mod;

    return ret;
  }
};
