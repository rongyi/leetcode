// http://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/
#include "xxx.h"

class Solution {
public:
  int subtractProductAndSum(int n) {
    vector<int> digits;
    int sum = 0;
    long long multi = 1;
    while (n) {
      auto cur = n % 10;
      sum += cur;
      multi *= cur;
      n /= 10;
    }

    return multi - (long long)sum;
  }
};
