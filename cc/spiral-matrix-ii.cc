// http://leetcode.com/problems/spiral-matrix-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n, std::vector<int>(n, 0));
    int total = n * n;
    int cur_cnt = 0;

    int right_end = n;
    int down_end = n;
    int left_end = -1;
    int up_end = 0;

    int x = 0;
    int y = 0;
    int d = 0;

    while (cur_cnt < total) {
      // right
      if (d == 0) {
        for (int j = y; j < right_end; j++) {
          ret[x][j] = ++cur_cnt;
        }
        right_end--;
        x += 1;
        y = right_end;
      } else if (d == 1) {
        for (int i = x; i < down_end; i++) {
          ret[i][y] = ++cur_cnt;
        }
        down_end--;
        y -= 1;
        x = down_end;
      } else if (d == 2) {
        for (int j = y; j > left_end; --j) {
          ret[x][j] = ++cur_cnt;
        }
        left_end++;
        x -= 1;
        y = left_end;
      } else {
        for (int i = x; i > up_end; --i) {
          ret[i][y] = ++cur_cnt;
        }
        up_end++;
        y += 1;
        x = up_end;
      }

      d = (d + 1) % 4;
    }

    return ret;
  }
};

