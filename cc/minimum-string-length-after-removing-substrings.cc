// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
#include "xxx.hpp"

class Solution {
public:
  int minLength(string s) {
    vector<char> l;
    for (auto &c: s) {
      if (!l.empty() && (l.back() == 'A' && c == 'B')) {
        l.pop_back();
      } else if (!l.empty() && (l.back() == 'C' && c == 'D')) {
        l.pop_back();
      } else {
        l.push_back(c);
      }

    }
    return l.size();
  }
};

class SolutionMyway {
public:
  int minLength(string s) {
    while (s.find("AB") != string::npos || s.find("CD") != string::npos) {
      if (s.find("AB") != string::npos) {
        s = s.erase(s.find("AB"), 2);
      }
      if (s.find("CD") != string::npos) {
        s = s.erase(s.find("CD"), 2);
      }
    }

    return s.size();
  }
};
