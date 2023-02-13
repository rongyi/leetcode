// http://leetcode.com/problems/spiral-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ret;
    int m = matrix.size();
    int n = matrix[0].size();
    int total = m * n;

    int x = 0;
    int y = 0;
    int right_end = n;
    int down_end = m;
    int left_end = -1;
    int up_end = 0;

    // 0 ->
    // 1 down
    // 2 <-
    // 3 up
    int direction = 0;

    while (ret.size() < total) {
      if (direction == 0) {
        for (int j = y; j < right_end; ++j) {
          ret.push_back(matrix[x][j]);
        }
        right_end--;
        x += 1;
        y = right_end;
      } else if (direction == 1) {
        for (int i = x; i < down_end; ++i) {
          ret.push_back(matrix[i][y]);
        }
        down_end--;
        x = down_end;
        y -= 1;

      } else if (direction == 2) {
        for (int j = y; j > left_end; --j) {
          ret.push_back(matrix[x][j]);
        }
        left_end++;
        x -= 1;
        y = left_end;
      } else {
        for (int i = x; i > up_end; --i) {
          ret.push_back(matrix[i][y]);
        }
        up_end++;
        x = up_end;
        y += 1;
      }

      direction = (direction + 1) % 4;
    }

    return ret;
  }
};
