// https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/
#include "xxx.hpp"

class Solution {
public:
  using FiveAndTwo = array<int, 2>;
  int maxTrailingZeros(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    // from left to right
    vector<vector<FiveAndTwo>> rows_prefix(m + 1, vector<FiveAndTwo>(n + 1));
    for (int j = 0; j < n; ++j) {
      rows_prefix[0][j] = {0, 0};
    }
    // from top to bottom
    vector<vector<FiveAndTwo>> cols_prefix(m + 1, vector<FiveAndTwo>(n + 1));
    for (int i = 0; i < m; ++i) {
      cols_prefix[i][0] = {0, 0};
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // from left to right
        auto cur = getnum(grid[i][j]);
        rows_prefix[i + 1][j + 1][0] = rows_prefix[i + 1][j][0] + cur[0];
        rows_prefix[i + 1][j + 1][1] = rows_prefix[i + 1][j][1] + cur[1];

        // from top to bottom
        cols_prefix[i + 1][j + 1][0] = cols_prefix[i][j + 1][0] + cur[0];
        cols_prefix[i + 1][j + 1][1] = cols_prefix[i][j + 1][1] + cur[1];
      }
    }

    int ret = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        FiveAndTwo from_bottom_to_here_exclude;
        FiveAndTwo from_right_to_here_exclude;
        auto cur = getnum(grid[i][j]);

        // from_bottom_to_here_exclude exclude current num
        from_bottom_to_here_exclude[0] =
            cols_prefix[m][j + 1][0] - cols_prefix[i + 1][j + 1][0];
        from_bottom_to_here_exclude[1] =
            cols_prefix[m][j + 1][1] - cols_prefix[i + 1][j + 1][1];
        // from_right_to_here_exclude exclude current num
        from_right_to_here_exclude[0] =
            rows_prefix[i + 1][n][0] - rows_prefix[i + 1][j + 1][0];
        from_right_to_here_exclude[1] =
            rows_prefix[i + 1][n][1] - rows_prefix[i + 1][j + 1][1];

        // -----
        //      |
        //      |
        ret = max(
            ret,
            min(from_bottom_to_here_exclude[0] + rows_prefix[i + 1][j + 1][0],
                from_bottom_to_here_exclude[1] + rows_prefix[i + 1][j + 1][1]));
        //  -------
        // |
        // |
        ret = max(ret, min(from_bottom_to_here_exclude[0] +
                               from_right_to_here_exclude[0] + cur[0],
                           from_bottom_to_here_exclude[1] +
                               from_right_to_here_exclude[1] + cur[1]));
        //       |
        //       |
        // ------
        // current is used twice!
        ret = max(ret, min(cols_prefix[i + 1][j + 1][0] +
                               rows_prefix[i + 1][j + 1][0] - cur[0],
                           cols_prefix[i + 1][j + 1][1] +
                               rows_prefix[i + 1][j + 1][1] - cur[1]));
        // |
        // |
        // |
        //  ---------
        ret = max(
            ret,
            min(cols_prefix[i + 1][j + 1][0] + from_right_to_here_exclude[0],
                cols_prefix[i + 1][j + 1][1] + from_right_to_here_exclude[1]));
      }
    }

    return ret;
  }

private:
  FiveAndTwo getnum(int n) {
    FiveAndTwo ret{0, 0};
    while (n % 5 == 0) {
      ret[0]++;
      n /= 5;
    }
    while (n % 2 == 0) {
      ret[1]++;
      n /= 2;
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<vector<int>> input{{23, 17, 15, 3, 20},
                            {8, 1, 20, 27, 11},
                            {9, 4, 6, 2, 21},
                            {40, 9, 1, 10, 6},
                            {22, 7, 4, 5, 3}};
  so.maxTrailingZeros(input);

  // 0:0 0:0 0:0 0:0 0:0 0:0
  // 0:0 0:0 0:0 1:0 1:0 2:2
  // 0:0 0:3 0:3 1:5 1:5 1:5
  // 0:0 0:0 0:2 0:3 0:4 0:4
  // 0:0 1:3 1:3 1:3 2:4 2:5
  // 0:0 0:1 0:1 0:3 1:3 1:3
  //====
  // 0:0 0:0 0:0 0:0 0:0 0:0
  // 0:0 0:0 0:0 1:0 0:0 1:2
  // 0:0 0:3 0:0 2:2 0:0 1:2
  // 0:0 0:3 0:2 2:3 0:1 1:2
  // 0:0 1:6 0:2 2:3 1:2 1:3
  // 0:0 1:7 0:2 2:5 2:2 1:3
  //

  return 0;
}
