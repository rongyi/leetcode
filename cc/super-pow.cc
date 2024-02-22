// http://leetcode.com/problems/super-pow/description/
#include "xxx.hpp"

class Solution {
public:
  int superPow(int a, vector<int> &b) {
    int ret = 1;
    for (int i = 0; i < b.size(); i++) {
      ret = pow(ret, 10) * pow(a, b[i]) % 1337;
    }
    return ret;
  }
  int pow(int a, int b) {
    if (b == 0) {
      return 1;
    }
    int ret = 1;
    int base = a % 1337;
    int exponent = b;

    while (exponent > 0) {
      if (exponent % 2 == 1) {
        ret = (ret * base) % 1337;
      }
      base = (base * base) % 1337;
      exponent /= 2;
    }
    return ret;
  }
};
