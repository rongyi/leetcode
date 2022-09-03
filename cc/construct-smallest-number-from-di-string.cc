// https://leetcode.com/problems/construct-smallest-number-from-di-string/
#include "xxx.hpp"

class Solution {
public:
  string smallestNumber(string pattern) {
    int sz = pattern.size();
    string ret;
    for (int i = 0, j = 0; i <= sz; ++i) {
      ret.push_back(i + '1');
      if (i == sz || pattern[i] == 'I') {
        reverse(ret.begin() + j, ret.end());
        j = i + 1;
      }
    }

    return ret;
  }
};
