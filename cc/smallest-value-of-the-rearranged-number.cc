// https://leetcode.com/problems/smallest-value-of-the-rearranged-number/
#include "xxx.hpp"

class Solution {
public:
  long long smallestNumber(long long num) {
    bool need_rsort = (num < 0);
    long long n = ::abs(num);
    if (n < 10) {
      return num;
    }

    string s = to_string(n);
    if (need_rsort) {
      sort(rbegin(s), rend(s));
    } else {
      sort(begin(s), end(s));
    }
    // check the leading zero
    // and swap the smallest nonzero digit to here
    if (s[0] == '0') {
      int j = 0;
      while (j < s.size() && s[j] == '0') {
        j++;
      }
      swap(s[0], s[j]);
    }
    long long ret = stoll(s);
    if (need_rsort) {
      return -ret;
    }

    return ret;
  }
};
