// http://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/description/
#include "xxx.h"

class Solution {
public:
  int minDays(int n) {
    if (n <= 1) {
      return n;
    }
    if (dp_.count(n) == 0) {
      dp_[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
    }

    return dp_[n];
  }

private:
  unordered_map<int, int> dp_;
};
