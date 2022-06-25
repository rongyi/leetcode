// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/
#include "xxx.hpp"

class Solution {
public:
  string greatestLetter(string s) {
    vector<int> lower(26, 0);
    vector<int> upper(26, 0);
    for (auto &c : s) {
      if (islower(c)) {
        lower[c - 'a'] += 1;
      } else {
        upper[c - 'A'] += 1;
      }
    }
    for (int i = 25; i >= 0; --i) {
      if (lower[i] > 0 && upper[i] > 0) {
        string ret;
        ret.push_back('A' + i);
        return ret;
      }
    }
    return "";
  }
};
