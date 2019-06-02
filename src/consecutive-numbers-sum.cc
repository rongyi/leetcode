// http://leetcode.com/problems/consecutive-numbers-sum/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/consecutive-numbers-sum/discuss/209317/topic
  // 引用自这个博客 https://zhanghuimeng.github.io/post/leetcode-829-consecutive-numbers-sum/
  // 实在看不下去了其他啰嗦的解法,就是等差数列好吗
  // 这道题的要求的另一种说法: 把N表示成一个等差数列（公差为1）的和
  // 我们不妨设这个数列的首项是x，项数为m，则这个数列的和就是[x + (x + (m-1))]m / 2 = mx + m(m-1)/2 = N
  // 接下来，一个很自然的想法就是，枚举m，通过上式判断对于相应的m是否存在合法的x。
  // x = ((N - m(m-1)/2)) / m
  // 显然枚举的复杂度是O(sqrt(N))。因为m能取到的最大值显然是sqrt(n)数量级的
  int consecutiveNumbersSum(int N) {
    int ret = 0;
    for (int m = 1;; m++) {
      int mx = N - m * (m - 1) / 2;
      if (mx <= 0) {
        break;
      }
      if (mx % m == 0) {
        ret++;
      }
    }

    return ret;
  }
};
