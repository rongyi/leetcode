// https://leetcode.com/problems/number-of-ways-to-select-buildings/
#include "xxx.hpp"

class Solution {
public:
  long long numberOfWays(string s) {
    int sz = s.size();
    vector<int> left_one(sz, 0);
    vector<int> left_zero(sz, 0);

    vector<int> right_one(sz, 0);
    vector<int> right_zero(sz, 0);

    for (int i = 0, lone = 0, lzero = 0; i < sz; ++i) {
      left_one[i] = lone;
      left_zero[i] = lzero;
      lone += s[i] == '1';
      lzero += s[i] == '0';
    }

    // or in one loop?
    for (int i = sz - 1, rone = 0, rzero = 0; i >= 0; --i) {
      right_one[i] = rone;
      right_zero[i] = rzero;

      rone += s[i] == '1';
      rzero += s[i] == '0';
    }
    long long ret = 0;
    for (int i = 0; i < sz; ++i) {
      if (s[i] == '0') {
        ret += (long long)left_one[i] * right_one[i];
      } else {
        ret += (long long)left_zero[i] * right_zero[i];
      }
    }

    return ret;
  }
};
