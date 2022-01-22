// http://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/
#include "xxx.hpp"

class Solution {
public:
  int countBalls(int lowLimit, int highLimit) {
    map<int, int> count;
    int ret = 0;
    auto ds = [](int n) {
      int ret = 0;
      while (n) {
        ret += n % 10;
        n /= 10;
      }
      return ret;
    };
    for (int i = lowLimit; i <= highLimit; ++i) {
      auto cur = ds(i);
      count[cur]++;
      ret = max(ret, count[cur]);
    }
    return ret;
  }
};
