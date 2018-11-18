// http://leetcode.com/problems/counting-bits/description/
#include "simpleone.h"

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> ret;
    for (int i = 0; i <= num; i++) {
      ret.push_back(cb(i));
    }
    return ret;
  }
public:
  int cb(int n) {
    int ret = 0;
    while (n) {
      if (n & 1) {
        ret++;
      }
      n >>= 1;
    }
    return ret;
  }
};
