// http://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/
#include "xxx.h"

class Solution {
public:
  int countGoodSubstrings(string s) {
    int sz = s.size();
    int total = 0;

    // i <= n - 3
    for (int i = 0; i < sz - 2; i++) {
      if (!(s[i] == s[i + 1] || s[i] == s[i + 2] || s[i + 1] == s[i + 2])) {
        total++;
      }
    }

    return total;
  }
};
