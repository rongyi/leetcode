// http://leetcode.com/problems/zigzag-conversion/description/
#include "one.h"

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    const int len = s.size();
    vector<vector<char>> help(numRows, vector<char>{});

    int row = 0;
    int col = 0;
    bool down = true;
    for (int i = 0; i < len; ++i) {
      if (down) {
        help[row++].push_back(s[i]);
        if (row == numRows) {
          down = false;
          col++;
          row--;
        }
      } else {
        help[--row].push_back(s[i]);
        if (row == 0) {
          down = true;
          row++;
        }
      }
    }

    stringstream ss;
    for (auto v: help) {
      for (auto c : v) {
        ss << c;
      }
    }
    return ss.str();
  }
};

int main() {
  Solution so;
  so.convert("PAYPALISHIRING", 4);
}
