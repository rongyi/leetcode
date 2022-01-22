// http://leetcode.com/problems/increasing-decreasing-string/description/
#include "xxx.hpp"

class Solution {
public:
  string sortString(string s) {
    int n = s.size();
    string ret;
    int count[26] = {};
    for (auto &c : s) {
      ++count[c - 'a'];
    }

    while (n) {
      for (int i = 0; i < 26; i++) {
        if (count[i]) {
          ret.push_back(i + 'a');
          --count[i];
          --n;
        }
      }
      for (int i = 25; i >= 0; i--) {
        if (count[i]) {
          ret.push_back(i + 'a');
          --count[i];
          --n;
        }
      }
    }

    return ret;
  }
};
