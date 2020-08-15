// http://leetcode.com/problems/smallest-integer-divisible-by-k/description/
#include "xxx.h"

class Solution {
public:
  // 喷的很惨
  int smallestRepunitDivByK(int K) {
    for (int m = 1, N = 1 % K; N <= K; m = (m * 10 + 1) % K, ++N) {
      if (m == 0) {
        return N;
      }
    }
    return -1;
  }
};
