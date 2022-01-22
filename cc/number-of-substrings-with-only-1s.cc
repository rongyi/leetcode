// http://leetcode.com/problems/number-of-substrings-with-only-1s/description/
#include "xxx.hpp"

class Solution {
public:
  Solution() : mod_(1e9 + 7) {}
  int numSub(string s) {
    int i = 0;
    int j = -1;
    int ret = 0;

    const int mod = pow(10, 9) + 7;

    while (i < s.size()) {
      if (s[i] == '0') {
        i++;
        continue;
      }
      // we meet our first 1
      j = i;
      while (j < s.size() && s[j] == '1') {
        ++j;
      }
      int cur_len = j - i;
      ret = (ret + total(cur_len)) % mod;
      // update i
      i = j;
    }

    return ret;
  }

private:
  long long total(long long n) {
    return (n % mod_ * (n + 1) % mod_ / 2) % mod_;
  }

private:
  int mod_;
};
