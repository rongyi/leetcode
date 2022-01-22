// http://leetcode.com/problems/complement-of-base-10-integer/description/
#include "xxx.hpp"

class Solution {
public:
  int bitwiseComplement(int N) {
    if (N == 0) {
      return 1;
    }
    int dc = 0;
    int cp = N;
    while (N) {
      ++dc;
      N >>= 1;
    }
    int ret = 0;
    for (int i = 0; i < dc; i++) {
      ret |= ((((cp >> i) & 1) ^ 1) << i);
    }
    return ret;
  }
};
