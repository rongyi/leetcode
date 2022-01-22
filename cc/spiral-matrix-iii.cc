// http://leetcode.com/problems/spiral-matrix-iii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int total = R * C;
    // 当前方向，初始向东
    int cur_dir = 0;
    // 当前长度, move to east or west, len++
    // 长度规律是 1 1 2 2 3 3 4 4 5 5
    int cur_len = 0;

    vector<vector<int>> ret{{r0, c0}};
    while (ret.size() < total) {
      if (cur_dir == 0 || cur_dir == 2) {
        cur_len++;
      }
      for (int i = 0; i < cur_len; i++) {
        r0 += dirs[cur_dir][0];
        c0 += dirs[cur_dir][1];
        // 就这么转，发现在这个矩形空间里的元素就添加上来
        if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
          ret.push_back({r0, c0});
        }
      }

      cur_dir = (cur_dir + 1) % 4;
    }

    return ret;
  }
};
