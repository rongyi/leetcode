// http://leetcode.com/problems/excel-sheet-column-number/description/
#include "xxx.h"

class Solution {
public:
  int titleToNumber(string s) {
    unordered_map<char, int> table;
    int i = 1;
    for (int j = 0; j < 26; j++) {
      table['A' + j] = i++;
    }

    int ret = 0;
    for (auto c: s) {
      ret = ret * 26 + table[c];
    }
    return ret;
  }
};
