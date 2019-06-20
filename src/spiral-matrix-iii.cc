// http://leetcode.com/problems/spiral-matrix-iii/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int total = R * C;
    // 当前方向，初始向东
    int cur_dir = 0;
    // 当前长度, move to east or west, len++
    int cur_len = 0;

    vector<vector<int>> ret{{r0, c0}};
    while (ret.size() < total) {
      if (cur_dir == 0 || cur_dir == 2) {
        cur_len++;
      }
      for (int i = 0; i < cur_len; i++) {
        r0 += dirs[cur_dir][0];
        c0 += dirs[cur_dir][1];
        if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
          ret.push_back({r0, c0});
        }
      }

      cur_dir = (cur_dir + 1) % 4;
    }

    return ret;
  }
};
