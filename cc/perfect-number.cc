// http://leetcode.com/problems/perfect-number/description/
#include "xxx.hpp"

class Solution {
public:
  bool checkPerfectNumber(int num) {
    if (num <= 1) {
      return false;
    }

    vector<int> divisors{1};
    for (int i = 2; i < num; i++) {
      if ((num % i) == 0) {
        divisors.push_back(i);
      }
    }

    return accumulate(divisors.begin(), divisors.end(), 0) == num;
  }
};
