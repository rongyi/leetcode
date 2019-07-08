// http://leetcode.com/problems/flip-string-to-monotone-increasing/description/
#include "xxx.h"

class Solution {
public:
  int minFlipsMonoIncr(string S) {
    int counter_one = 0;
    int flip_count = 0;
    for (auto ch : S) {
      if (ch == '1') {
        ++counter_one;
      } else {
        ++flip_count;
      }
      flip_count = min(flip_count, counter_one);
    }

    return flip_count;
  }
};
