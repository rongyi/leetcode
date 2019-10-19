// http://leetcode.com/problems/largest-1-bordered-square/description/
#include "xxx.h"

class Solution {
public:
  // largest square wihch edge are all 1
  // https://leetcode.com/problems/largest-1-bordered-square/discuss/345265/c%2B%2B-beats-100-(both-time-and-memory)-concise-with-algorithm-and-image
  int largest1BorderedSquare(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    vector<vector<int>> horizon_incre(m, vector<int>(n, 0));
    vector<vector<int>> vertical_incre(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          horizon_incre[i][j] = (j == 0 ? 0 : horizon_incre[i][j - 1]) + 1;
          vertical_incre[i][j] = (i == 0 ? 0 : vertical_incre[i - 1][j]) + 1;
        }
      }
    }
    int max_edge = 0;

    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {

        // a---------b
        // |       |
        // |       |
        // |       |
        // c--------d (i, j)
        // start from d, get min(cd, bd), if we get a square
        // ac and ab must be checked either.
        // ac == vertical_incre[i][j - cur_edge + 1]
        // ab == horizon_incre[i - cur_edge + 1][j]
        int cur_edge = min(horizon_incre[i][j], vertical_incre[i][j]);
        while (cur_edge > max_edge) {
          if (vertical_incre[i][j - cur_edge + 1] >= cur_edge &&
              horizon_incre[i - cur_edge + 1][j] >= cur_edge) {
            max_edge = cur_edge;
            break;
          }
          cur_edge--;
        }
      }
    }

    return max_edge * max_edge;
  }
};
