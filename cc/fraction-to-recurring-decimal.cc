// http://leetcode.com/problems/fraction-to-recurring-decimal/description/
#include "xxx.h"

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
      return "0";
    }
    string ret;

    if (numerator < 0 ^ denominator < 0) {
      ret += '-';
    }
    // make it in large range
    long long n = numerator;
    n = llabs(n);
    long long d = denominator;
    d = llabs(d);

    ret += to_string(n / d);
    long long int r = n % d;
    if (r == 0) {
      return ret;
    } else {
      ret += '.';
    }
    // fraction part
    unordered_map<int, int> cache;
    while (r) {
      if (cache.find(r) != cache.end()) {
        ret.insert(cache[r], 1, '(');
        ret += ')';
        break;
      }
      cache[r] = ret.size();

      r *= 10;
      ret += to_string(r / d);
      r = r % d;
    }
    return ret;
  }
};
