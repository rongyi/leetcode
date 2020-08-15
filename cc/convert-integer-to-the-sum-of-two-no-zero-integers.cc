// http://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/
#include "xxx.h"

class Solution {
public:
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i < n; i++) {
      int j = n - i;
      if (containZero(i) || containZero(j)) {
        continue;
      }
      return {i, j};
    }
    return {-1, -1};
  }

private:
  bool containZero(int n) {
    if (n == 0) {
      return true;
    }

    while (n) {
      if (n % 10 == 0) {
        return true;
      }
      n /= 10;
    }
    return false;
  }
};
