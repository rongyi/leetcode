// http://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/discuss/103754/C%2B%2B-Non-DP-O(32)-Fibonacci-solution
  // the number of length k string without consecutive 1 is Fibonacci sequence f(k);
  // For example, if k = 5, the range is 00000-11111. We can consider it as two ranges, which are 00000-01111 and 10000-10111. Any number >= 11000 is not allowed due to consecutive 1. The first case is actually f(4), and the second case is f(3), so f(5)= f(4)+f(3).

  // Scan the number from most significant digit, i.e. left to right, in binary format. If we find a '1' with k digits to the right, count increases by f(k) because we can put a '0' at this digit and any valid length k string behind; After that, we continue the loop to consider the remaining cases, i.e., we put a '1' at this digit. If consecutive 1s are found, we exit the loop and return the answer. By the end of the loop, we return count+1 to include the number n itself.

  // For example, if n is 10010110,
  // we find first '1' at 7 digits to the right, we add range 00000000-01111111, which is f(7);
  // second '1' at 4 digits to the right, add range 10000000-10001111, f(4);
  // third '1' at 2 digits to the right, add range 10010000-10010011, f(2);
  // fourth '1' at 1 digits to the right, add range 10010100-10010101, f(1);
  // Those ranges are continuous from 00000000 to 10010101. And any greater number <= n will have consecutive 1.
  int findIntegers(int num) {
    int f[32]{};
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i < 32; i++) {
      f[i] = f[i - 1] + f[i - 2];
    }
    int ret = 0;
    int k = 30;
    bool is_prev_one = false;
    while (k >= 0) {
      if (num &(1 << k)) {
        ret += f[k];
        // 连续1出现之后就只有一种情况出现，就是当前位置0后产生的f(k)，
        // 当前位不能再有1的情况了，因为连续了，所以终止到这里
        if (is_prev_one) {
          return ret;
        }
        is_prev_one = true;
      } else {
        is_prev_one = false;
      }
      --k;
    }
    return ret + 1;
  }
};
