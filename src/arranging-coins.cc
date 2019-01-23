// http://leetcode.com/problems/arranging-coins/description/
#include "xxx.h"

class Solution {
public:
  int arrangeCoins(int n) {
    if (n == 0) {
      return 0;
    }

    int cur_sum = 0;
    int i = 1;

    while (true) {
      cur_sum += i;
      i++;
      if (n - cur_sum < i) {
        break;
      }
    }

    return i - 1;
  }
};
