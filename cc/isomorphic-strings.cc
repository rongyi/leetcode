// http://leetcode.com/problems/isomorphic-strings/description/
#include "xxx.hpp"

class Solution {
public:
  bool isIsomorphic(string s, string t) { return check(s, t) && check(t, s); }

private:
  bool check(string &s, string &t) {
    map<char, char> bind;
    for (int i = 0; i < s.size(); i++) {
      if (bind.count(s[i]) && bind[s[i]] != t[i]) {
        return false;
      }
      bind[s[i]] = t[i];
    }

    return true;
  }
};

