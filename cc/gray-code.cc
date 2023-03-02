// http://leetcode.com/problems/gray-code/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> grayCode(int n) {
    // 0000
    // 0000 0001
    // 0000 0001 0011 0010
    // 0000 0001 0011 0010 0110 0111 0101 0100
    vector<int> ret{0};
    for (int i = 1; i <= n; i++) {
      int prev_len = ret.size();
      int mask = 1 << (i - 1);
      for (int j = prev_len - 1; j >= 0; j--) {
        ret.push_back(mask | ret[j]);
      }
    }

    return ret;
  }
};
