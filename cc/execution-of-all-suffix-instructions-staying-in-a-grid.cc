// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/
#include "xxx.hpp"

class Solution {
public:
  vector<int> executeInstructions(int n, vector<int> &startPos, string s) {
    auto valid = [&](int x, int y) -> bool {
      if (x < 0 || x >= n || y < 0 || y >= n) {
        return false;
      }
      return true;
    };
    int sz = s.size();
    vector<int> ret(sz, 0);
    for (int i = 0; i < sz; ++i) {
      int cur_steps = 0;
      int x = startPos[0];
      int y = startPos[1];

      for (int j = i; j < sz; ++j) {
        char d = s[j];
        if (d == 'U') {
          --x;
        } else if (d == 'D') {
          ++x;
        } else if (d == 'R') {
          ++y;
        } else {
          --y;
        }
        if (valid(x, y)) {
          ++cur_steps;
        } else {
          break;
        }
      }

      ret[i] = cur_steps;
    }

    return ret;
  }
};
