// https://leetcode.com/problems/minimize-string-length/
#include "xxx.hpp"

class Solution {
public:
  int minimizedStringLength(string s) {
    int sz = s.size();
    set<char> uniq;

    for (int i = 0; i < sz; i++) {
      uniq.insert(s[i]);
    }

    return uniq.size();
  }
};
