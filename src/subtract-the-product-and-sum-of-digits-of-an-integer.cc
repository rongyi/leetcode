// http://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/
#include "xxx.h"

class Solution {
public:
  int subtractProductAndSum(int n) {
    vector<int> digits;
    while (n) {
      digits.push_back(n % 10);
      n /= 10;
    }
    auto sum = accumulate(digits.begin(), digits.end(), 0);
    long long multi = 1;
    for (auto d : digits) {
      multi *= d;
    }

    return multi - (long long)sum;
  }
};
