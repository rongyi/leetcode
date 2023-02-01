// http://leetcode.com/problems/zigzag-conversion/description/
#include "xxx.hpp"

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    int sz = s.size();
    vector<string> rows(sz);

    int i = 0;
    bool is_down = true;
    int cur_row = 0;
    while (i < sz) {
      if (is_down) {
        rows[cur_row++].push_back(s[i]);
        if (cur_row == numRows) {
          is_down = false;
          cur_row = numRows - 2;
        }
      } else {
        rows[cur_row--].push_back(s[i]);
        if (cur_row < 0) {
          is_down = true;
          cur_row = 1;
        }
      }
      i++;
    }
    ostringstream ss;
    for (auto &r: rows) {
      ss << r;
    }

    return ss.str();
  }
};

int main() {
  Solution so;
  so.convert("PAYPALISHIRING", 4);
}
