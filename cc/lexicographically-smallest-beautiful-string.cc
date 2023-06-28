// https://leetcode.com/problems/lexicographically-smallest-beautiful-string/
#include "xxx.hpp"

class Solution {
public:
  // input s is also beautiful
  string smallestBeautifulString(string s, int k) {
    int sz = s.size();
    auto valid = [&](int i) {
      return ((i < 1) || s[i] != s[i - 1]) && (i < 2 || s[i] != s[i - 2]);
    };

    for (int i = sz - 1; i >= 0; i--) {
      ++s[i];
      while (!valid(i)) {
        ++s[i];
      }
      if (s[i] < 'a' + k) {
        for (i = i + 1; i < sz; ++i) {
          s[i] = 'a';
          while (!valid(i)) {
            ++s[i];
          }
        }
        return s;
      }
    }
    return "";
  }
};
