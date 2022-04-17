// https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/
#include "xxx.hpp"

class Solution {
public:
  long long maximumSubsequenceCount(string text, string pattern) {
    // case 1
    // add first char to begin
    string c1 = string{pattern[0]} + text;
    // case1:
    // add second char to end;
    text.push_back(pattern[1]);

    return max(subsequencesCount(c1, pattern),
               subsequencesCount(text, pattern));
  }

private:
  long long subsequencesCount(string &s, string &pat) {
    long long ret = 0;
    int sz = s.size();
    char first = pat[0];
    char second = pat[1];
    long long prevFirst = 0;

    for (int i = 0; i < sz; ++i) {
      if (s[i] == first) {
        prevFirst++;
      } else if (s[i] == second) {
        ret += prevFirst;
      }
    }
    // e.g. yyy we have
    //      ^^  yy
    //      ^ ^ yy
    //       ^^ yy
    //      3 case here
    if (pat[0] == pat[1]) {
      return prevFirst * (prevFirst - 1) / 2;
    }
    return ret;
  }
};
