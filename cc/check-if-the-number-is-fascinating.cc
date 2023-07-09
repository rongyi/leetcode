// https://leetcode.com/problems/check-if-the-number-is-fascinating/
#include "xxx.hpp"

class Solution {
public:
  bool isFascinating(int n) {
    set<char> uniq;
    for (int i = 1; i <= 3; i++) {
      string s = to_string(n * i);
      for (auto c : s) {
        if (c == '0') {
          return false;
        }
        if (uniq.count(c)) {
          return false;
        }
        uniq.insert(c);
      }
    }

    return uniq.size() == 9;
  }
};
