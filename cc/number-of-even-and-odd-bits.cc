// https://leetcode.com/problems/number-of-even-and-odd-bits/
#include "xxx.hpp"

class Solution {
public:
  vector<int> evenOddBit(int n) {
    int even_cnt = 0;
    int odd_cnt = 0;
    for (int i = 0; n > 0; i++) {
      if (n & 1) {
        if (i & 1) {
          odd_cnt++;
        } else {
          even_cnt++;
        }
      }

      n >>= 1;
    }
    return {even_cnt, odd_cnt};
  }
};
