// http://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/
#include_next "xxx.h"

class Solution {
public:
  int maxValue(int n, int index, int maxSum) {
    maxSum -= n;
    int left = 0;
    int right = maxSum;

    while (left < right) {
      int mid = (left + right + 1) / 2;
      if (cur_sum(n, index, mid) <= maxSum) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }

    return left + 1;
  }

private:
  long cur_sum(int n, int index, int a) {
    // left most
    int b = max(a - index, 0);
    // 等差数列，delta为1的sum公式
    long ret = long(a + b) * (a - b + 1) / 2;
    // right most
    b = max(a - ((n - 1) - index), 0);
    // 同样等差数列
    ret += long(a + b) * (a - b + 1) / 2;

    // 中间的"最高峰"重复了一次
    return ret - a;
  }
};
