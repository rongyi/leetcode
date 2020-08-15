// http://leetcode.com/problems/smallest-good-base/description/
#include "xxx.h"

class Solution {
public:
  string smallestGoodBase(string n) {
    using ull = unsigned long long;
    const ull num = stoll(n);
    // this loop will iterate length from max possible value to min value
    // when base == 2, we have longest length of '1'
    // 2^0 + 2^1 + ... + 2^(len - 1) == num -> 2^len == num + 1 -> len = log(num + 1) base on 2
    // log(num + 1) / log(2) == log (num + 1) base on 2
    for (int len = log(num + 1) / log(2); len >= 2; len--) {

      // n = 1 + k + k^2 + k^3 + ... + k^(m-1) > k^(m-1)
      // -> k < n^(1 / m - 1)
      ull l = 2;
      // 加1 ==> 类似python ceil函数作用
      ull r = pow(num, 1.0 / (len - 1)) + 1;

      while (l < r) {
        ull sum = 0;
        ull base = l + (r - l) / 2;
        ull val = 1;
        for (int i = 0; i < len; ++i) {
          sum += val;
          val *= base;
        }
        if (sum == num) {
          return to_string(base);
        } else if (sum < num) {
          l = base + 1;
        } else {
          r = base;
        }
      }
    }

    return to_string(num - 1);
  }
};
