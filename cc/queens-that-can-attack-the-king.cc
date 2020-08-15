// http://leetcode.com/problems/queens-that-can-attack-the-king/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens,
                                          vector<int> &king) {
    vector<vector<int>> ret;
    bool b[8][8] = {};
    for (auto &q : queens) {
      b[q[0]][q[1]] = true;
    }
    for (auto i = -1; i <= 1; ++i) {
      for (auto j = -1; j <= 1; ++j) {
        // 四个方向，这个不合法
        if (i == 0 && j == 0) {
          continue;
        }
        int nx = king[0] + i;
        int ny = king[1] + j;
        while (min(nx, ny) >= 0 && max(nx, ny) < 8) {
          if (b[nx][ny]) {
            ret.push_back({nx, ny});
            break;
          }
          nx += i;
          ny += j;
        }
      }
    }

    return ret;
  }
};
