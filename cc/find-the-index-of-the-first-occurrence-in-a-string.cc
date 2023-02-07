// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
#include "xxx.hpp"

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) {
      return 0;
    }
    int hsz = haystack.size();
    int nsz = needle.size();
    auto lps = genLps(needle);
    for (int i = 0, j = 0; i < hsz;) {
      if (needle[j] == haystack[i]) {
        i++;
        j++;
      }
      if (j == nsz) {
        return i - nsz;
      }
      if (i < hsz && needle[j] != haystack[i]) {
        if (j > 0) {
          j = lps[j - 1];
        } else {
          i++;
        }
      }
    }
    return -1;
  }

private:
  vector<int> genLps(string &s) {
    int sz = s.size();
    vector<int> ret(sz, 0);
    for (int i = 1, len = 0; i < sz;) {
      if (s[i] == s[len]) {
        ret[i] = len + 1;
        i++;
        len++;
      } else {
        if (len > 0) {
          len = ret[len - 1];
        } else {
          i++;
        }
      }
    }
    return ret;
  }
};
