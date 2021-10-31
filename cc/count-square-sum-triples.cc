// https://leetcode.com/problems/count-square-sum-triples/
#include "xxx.h"

class Solution {
public:
  int countTriples(int n) {
    int ret = 0;
    vector<bool> square(n * n + 1, false);
    // prepare the c
    for (int i = 1; i <= n; ++i) {
      square[i * i] = true;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i; i * i + j * j <= n * n; ++j) {
        ret += square[i * i + j * j] * 2;
      }
    }
    return ret;
  }
};
