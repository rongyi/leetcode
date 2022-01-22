// http://leetcode.com/problems/count-number-of-homogenous-substrings/description/
#include "xxx.hpp"

class Solution {
public:
  int countHomogenous(string s) {
    const int mod = 1e9 + 7;
    const int n = s.size();
    long long ret = 0;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && s[j] == s[i]) {
        j++;
      }
      long long len = j - i;
      long long cur_count = len * (len + 1) / 2 % mod;
      ret += cur_count;
      ret %= mod;
      i = j;
    }

    return ret;
  }
};
