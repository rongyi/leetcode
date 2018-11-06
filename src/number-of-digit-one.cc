// http://leetcode.com/problems/number-of-digit-one/description/
#include "simpleone.h"

class Solution {
public:
  // 这道题没啥意思
  // https://leetcode.com/articles/number-of-digit-one/
  int countDigitOne(int n) {
    int countr = 0;
    for (long long i = 1; i <= n; i *= 10) {
      long long divider = i * 10;
      countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
    }
    return countr;
  }
};
