// https://leetcode.com/problems/count-integers-with-even-digit-sum/
#include "xxx.hpp"

class Solution {
public:
  int countEven(int num) {
    int cnt = 0;
    for (int i = 1; i <= num; ++i) {
      if ((digitSum(i) & 1) == 0) {
        cnt++;
      }
    }
    return cnt;
  }

private:
  int digitSum(int n) {
    int sum = 0;
    while (n) {
      sum += (n % 10);
      n /= 10;
    }
    return sum;
  }
};
