// http://leetcode.com/problems/find-the-difference/description/
#include "xxx.hpp"

class Solution {
public:
  char findTheDifference(string s, string t) {
    int ret = 0;
    for (auto c : s) {
      ret ^= c;
    }
    for (auto c : t) {
      ret ^= c;
    }
    return (char)ret;
  }
};
