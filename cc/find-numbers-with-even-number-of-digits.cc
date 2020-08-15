// http://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/
#include "xxx.h"

class Solution {
public:
  int findNumbers(vector<int> &nums) {
    int ret = 0;
    for (const auto &n : nums) {
      if ((dcount(n) & 1) == 0) {
        ++ret;
      }
    }

    return ret;
  }

public:
  int dcount(int n) {
    int ret = 0;
    while (n) {
      ++ret;
      n /= 10;
    }
    return ret;
  }
};
