// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
#include "xxx.hpp"

class Solution {
public:
  int maxPalindromes(string s, int k) {
    int ret = 0;
    int sz = s.size();

    for (int i = 0; i < sz; ++i) {
      for (int j = i; j < sz; ++j) {
        int len = (j - i) + 1;
        if (len > k + 1) {
          break;
        }
        if (len >= k && isParlindrom(s, i, j)) {
          ret++;
          i = j;
          break;
        }
      }
    }

    return ret;
  }

private:
  bool isParlindrom(string &s, int i, int j) {
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }

      ++i;
      --j;
    }
    return true;
  }
};
