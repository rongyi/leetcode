// https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/
#include "xxx.hpp"

class Solution {
public:
  int minOperations(int n) {
    int cnt = 0;
    while (n > 0) {
      if ((n & 3) == 3) {
        n++;
        cnt++;
      } else {
        cnt += n & 1;
        n >>= 1;
      }
    }

    return cnt;
  }
};
