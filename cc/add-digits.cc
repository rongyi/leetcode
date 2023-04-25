// http://leetcode.com/problems/add-digits/description/
#include "xxx.hpp"

class Solution {
public:
  int addDigits(int num) {
    auto dsum = [](int n) -> int {
      int ret = 0;
      while (n) {
        ret += (n % 10);
        n /= 10;
      }
      return ret;
    };
    while (num > 9) {
      num = dsum(num);
    }

    return num;
  }
};
