// https://leetcode.com/problems/removing-stars-from-a-string/
#include "xxx.hpp"

class Solution {
public:
  string removeStars(string s) {
    string ret;
    for (auto &c : s) {
      if (c == '*') {
        if (ret.size()) {
          ret.pop_back();
        }
      } else {
        ret.push_back(c);
      }
    }

    return ret;
  }
};
