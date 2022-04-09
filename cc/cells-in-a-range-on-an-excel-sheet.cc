// https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/
#include "xxx.hpp"

class Solution {
public:
  vector<string> cellsInRange(string s) {
    int start_row = s[1] - '0';
    int end_row = s[4] - '0';
    int start_col = s[0] - 'A';
    int end_col = s[3] - 'A';
    vector<string> ret;
    // traverse by row
    for (int j = start_col; j <= end_col; ++j) {
      for (int i = start_row; i <= end_row; ++i) {
        string cur{};
        cur.push_back(j + 'A');
        cur.push_back(i + '0');

        ret.push_back(cur);
      }
    }

    return ret;
  }
};
