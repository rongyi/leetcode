// http://leetcode.com/problems/excel-sheet-column-title/description/
#include "xxx.hpp"

class Solution {
public:
  string convertToTitle(int n) {
    string ret;
    n--;
    while (n >= 26) {
      ret += 'A' + (n % 26);
      n = n / 26 - 1;
    }
    ret += 'A' + n;

    reverse(ret.begin(), ret.end());

    return ret;
  }
};
