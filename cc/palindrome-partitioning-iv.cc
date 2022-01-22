// http://leetcode.com/problems/palindrome-partitioning-iv/description/
#include "xxx.hpp"

class Solution {
public:
  bool checkPartitioning(string s) {
    for (int i = 2; i < s.size(); ++i) {
      if (ispal(s, i, s.size() - 1)) {
        for (int j = 1; j < i; ++j) {
          if (ispal(s, j, i - 1) && ispal(s, 0, j - 1)) {
            return true;
          }
        }
      }
    }
    return false;
  }

private:
  bool ispal(string &s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }
    return true;
  }
};
