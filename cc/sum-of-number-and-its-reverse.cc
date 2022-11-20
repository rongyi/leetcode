// https://leetcode.com/problems/sum-of-number-and-its-reverse/
#include "xxx.hpp"

class Solution {
public:
  bool sumOfNumberAndReverse(int num) {
    auto revnum = [](int n) {
      int sum = 0;
      while (n) {
        sum *= 10;
        sum += (n % 10);
        n /= 10;
      }

      return sum;
    };
    for (int i = 0; i <= num; ++i) {
      if ((i + revnum(i)) == num) {
        return true;
      }
    }
    return false;
  }
};
