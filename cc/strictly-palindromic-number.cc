// https://leetcode.com/problems/strictly-palindromic-number/
#include "xxx.hpp"

class Solution {
public:
  bool isStrictlyPalindromic(int n) {
    for (int i = 2; i <= n - 2; i++) {
      auto cur = tostring(n, i);
      if (!check(cur)) {
        return false;
      }
    }

    return true;
  }

private:
  bool check(string &s) {
    int i = 0;
    int j = s.size() - 1;
    while (i <= j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
  string tostring(int n, int base) {
    if (n == 0) {
      return "0";
    }

    string ret;
    while (n != 0) {
      ret.push_back(n % base);
      n /= base;
    }

    return ret;
  }
};

