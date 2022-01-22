// http://leetcode.com/problems/reordered-power-of-2/description/
#include "xxx.hpp"

class Solution {
public:
  bool reorderedPowerOf2(int n) {
    if (n < 10) {
      return (n == 1 || n == 2 || n == 4 || n == 8);
    }
    multiset<int> digitsn;
    int num = n;
    int dc = 0;
    long long powerOf2 = 8;
    while (num) {
      digitsn.insert(num % 10);
      num /= 10;
      dc++;
    }

    for (int i = 4; i <= 4 * dc; i++) {
      powerOf2 *= 2;
      multiset<int> curdigits = convert(powerOf2);
      if (digitsn == curdigits) {
        return true;
      }
    }
    return false;
  }

private:
  multiset<int> convert(long long num) {
    multiset<int> ret;
    while (num) {
      ret.insert(num % 10);
      num /= 10;
    }

    return ret;
  }
};
