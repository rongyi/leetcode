// http://leetcode.com/problems/fraction-to-recurring-decimal/description/
#include "xxx.hpp"

class Solution {
public:
  string fractionToDecimal(int num, int div) {
    if (num == 0) {
      return "0";
    }
    string ret;
    if ((num < 0) ^ (div < 0)) {
      ret.push_back('-');
    }
    long long n = num;
    n = abs(n);
    long long d = div;
    d = abs(div);
    ret += to_string(n / d);
    if ((n % d) == 0) {
      return ret;
    }
    ret.push_back('.');

    long long rem = n % d;
    map<long long, int> pos;
    while (rem) {
      if (pos.count(rem)) {
        ret.insert(pos[rem], "(");
        ret.push_back(')');
        return ret;
      }

      pos[rem] = ret.size();
      rem *= 10;
      ret += to_string(rem / d);
      rem %= d;
    }

    return ret;
  }
};
