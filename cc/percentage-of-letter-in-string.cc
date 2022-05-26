// https://leetcode.com/problems/percentage-of-letter-in-string/
#include "xxx.hpp"

class Solution {
public:
  int percentageLetter(string s, char letter) {
    double total = s.size();
    int occ = 0;

    for (auto c : s) {
      if (c == letter) {
        occ++;
      }
    }

    return (occ / total) * 100;
  }
};
