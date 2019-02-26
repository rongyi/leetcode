// http://leetcode.com/problems/implement-rand10-using-rand7/description/
#include "xxx.h"

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
  // Range of a is from 1 to 6, range of b is from 1 to 5, probability of a < 4
  // is 1/2, probability of b = 1|2|3|4|5 is 1/5. Then, b + (a < 4 ? 5 : 0) =
  // 1|2|...|10, their probability is 1/10.
  int rand10Method1() {
    int a = 7;
    int b = 7;
    while (a == 7) {
      a = rand7();
    }
    while (b > 5) {
      b = rand7();
    }
    return b + (a < 4 ? 5 : 0);
  }
  int rand10() {
    int num;
    while ((num = (7 * (rand7() - 1) + rand7() - 1)) >= 40)
      ;
    return num % 10 + 1;
  }
};
