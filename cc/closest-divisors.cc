// http://leetcode.com/problems/closest-divisors/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> closestDivisors(int num) {
    auto d1 = largestDivisor(num + 1);
    auto d2 = largestDivisor(num + 2);
    auto diff1 = abs(d1 - (num + 1) / d1);
    auto diff2 = abs(d2 - (num + 1) / d2);
    if (diff1 <= diff2) {
      return {d1, (num + 1) / d1};
    }
    return {d2, (num + 2) / d2};
  }

private:
  int largestDivisor(int num) {
    int mid = sqrt(num);
    while (num % mid != 0) {
      --mid;
    }
    return mid;
  }
};
