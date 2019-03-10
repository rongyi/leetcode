// http://leetcode.com/problems/perfect-number/description/
#include "xxx.h"

class Solution {
public:
  bool checkPerfectNumber(int num) {
    if (num <= 1) {
      return false;
    }

    vector<int> divisor{1};
    for (int i = 2; i < num; i++) {
      if ((num % i) == 0) {
        divisor.push_back(i);
      }
    }

    return accumulate(divisor.begin(), divisor.end(), 0) == num;
  }
};
