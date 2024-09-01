// http://leetcode.com/problems/reordered-power-of-2/description/
#include "xxx.hpp"
#include <vector>

class Solution {
public:
  bool reorderedPowerOf2(int n) {
    auto expect = digit_count(n);
    for (int i = 0; i < 31; i++) {
      auto cur = digit_count(1 << i);
      if (cur == expect) {
        return true;
      }
    }
    return false;
  }

private:
  vector<int> digit_count(int n) {
    vector<int> ret(10, 0);
    while (n) {
      ret[n % 10] += 1;
      n /= 10;
    }

    return ret;
  }
};
