// http://leetcode.com/problems/count-good-meals/description/
#include "xxx.h"

class Solution {
public:
  int countPairs(vector<int> &deliciousness) {
    const int mod = 1e9 + 7;
    map<int, int> count;
    long ret = 0;
    for (auto &d : deliciousness) {
      int power = 1;
      // 题目出的没意思，这里循环丑的很
      for (int i = 0; i < 22; ++i) {
        if (count.count(power - d)) {
          ret += count[power - d];
          ret %= mod;
        }
        power *= 2;
      }

      count[d]++;
    }

    return ret;
  }
};
