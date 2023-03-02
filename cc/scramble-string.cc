// http://leetcode.com/problems/leetcode/scramble-string/description/
#include "xxx.hpp"

class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1 == s2) {
      return true;
    }
    int sz1 = s1.size();
    int sz2 = s2.size();
    if (sz1 != sz2) {
      return false;
    }
    // "a" "c"
    if (sz1 == 1) {
      return false;
    }
    string key = s1 + "|" + s2;
    if (dp_.count(key)) {
      return dp_[key];
    }
    // "g r e a t"
    //   | | | |
    for (int i = 1; i < sz1; i++) {
      auto check1 = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                    isScramble(s1.substr(i), s2.substr(i));
      if (check1) {
        return true;
      }
      // "great" "rgeat"
      //  g <> t
      auto check2 = isScramble(s1.substr(0, i), s2.substr(sz1 - i)) &&
                    isScramble(s1.substr(i), s2.substr(0, sz1 - i));
      if (check2) {
        return true;
      }
    }
    dp_[key] = false;
    return false;
  }

private:
  map<string, bool> dp_;
};
