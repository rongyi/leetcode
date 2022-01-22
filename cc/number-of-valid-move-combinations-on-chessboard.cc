// https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/
#include "xxx.hpp"

// dissed problem!
// https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/discuss/1549577/Dull-and-Painful
class Solution {
public:
  int countCombinations(vector<string> &pieces, vector<vector<int>> &pos,
                        int cur = 0) {
    dirs_ = {{0, 1}, {1, 0},  {0, -1},  {-1, 0} /* straight line*/,
             {1, 1}, {1, -1}, {-1, -1}, {-1, 1} /* diagonal line */};
    if (cur >= pieces.size()) {
      // find one!
      return 1;
    }
    // origin position
    int i = pos[cur][0] - 1;
    int j = pos[cur][1] - 1;

    int ret = 0;
    for (int d = 0; d < 8; ++d) {
      // bishop can only walk diagonally
      if (d < 4 && pieces[cur] == "bishop") {
        continue;
      }
      // rook can only go straight
      if (d >= 4 && pieces[cur] == "rook") {
        continue;
      }
      bool blocked = false;

      // for every direction we try each step we *can* reach
      // the original place only count once for one direction
      // after that, we don't count origin position
      for (int step = (ret == 0 ? 1 : 2); !blocked; ++step) {
        auto nx = i + (step - 1) * dirs_[d][0];
        auto ny = j + (step - 1) * dirs_[d][1];
        // invalid step
        if (min(nx, ny) < 0 || max(nx, ny) >= 8) {
          break;
        }
        bool can_stop = true;
        for (int prev = 0; prev < cur; ++prev) {
          // 1. no other pieces stopped at that position,
          // 2. other pieces already went through that position (transitional
          // position with less number of steps).
          can_stop &= b[prev][nx][ny] >= 0 && b[prev][nx][ny] < step;
          // 1. a final one for another piece with smaller/same number of steps
          // to get there,
          // 2. a transitional position for another piece with the same number
          // of steps to get there.
          blocked |= (b[prev][nx][ny] < 0 && -b[prev][nx][ny] <= step) ||
                     (b[prev][nx][ny] == step);
        }
        if (can_stop) {
          // To indicate the final position, we will use a negative number of
          // steps. cur stop at (nx, ny)
          b[cur][nx][ny] = -step;
          ret += countCombinations(pieces, pos, cur + 1);
        }
        // this is the steps cur get through (nx, ny)
        // transitional number of steps
        b[cur][nx][ny] = step;
      }

      fill_n(b[cur][0], 64, 0);
    }

    return ret;
  }

private:
  vector<vector<int>> dirs_;
  // 1 <= n <= 4
  int b[4][8][8] = {};
};
