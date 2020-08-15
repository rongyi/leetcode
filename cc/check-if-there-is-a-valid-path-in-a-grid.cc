// http://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/
#include "xxx.h"

class Solution {
public:
  bool hasValidPath(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<bool>> expand(m * 3, vector<bool>(n * 3, false));

    // https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/discuss/547225/C%2B%2B-with-picture%3A-track-direction-%2B-upscaled-grid
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        expand[i * 3 + 1][j * 3 + 1] = true;
        auto v = grid[i][j];
        if (v == 2 || v == 5 || v == 6) {
          expand[i * 3 + 0][j * 3 + 1] = true;
        }
        if (v == 1 || v == 3 || v == 5) {
          expand[i * 3 + 1][j * 3 + 0] = true;
        }
        if (v == 2 || v == 3 || v == 4) {
          expand[i * 3 + 2][j * 3 + 1] = true;
        }
        if (v == 1 || v == 4 || v == 6) {
          expand[i * 3 + 1][j * 3 + 2] = true;
        }
      }
    }

    return dfs(expand, 1, 1);
  }

private:
  bool dfs(vector<vector<bool>> &expand, int i, int j) {
    if (i < 0 || j < 0 || i >= expand.size() || j >= expand[0].size() ||
        !expand[i][j]) {
      return false;
    }
    if (i == expand.size() - 2 && j == expand[0].size() - 2) {
      return true;
    }
    // mark as visited
    expand[i][j] = false;
    return dfs(expand, i + 1, j) || dfs(expand, i - 1, j) ||
           dfs(expand, i, j + 1) || dfs(expand, i, j - 1);
  }

private:
#if 0
  // my problem is when the start is a turn , you should go right and down two
  // times to check the valid path
  bool hasValidPathFirstTry(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    unordered_set<int> visited;

    int i = 0;
    int j = 0;
    // alreay at the end
    if (i == m - 1 && j == n - 1) {
      return true;
    }
    // flow direction, initial to right
    bool right = true;
    // flow direction, initial to down
    bool down = true;
    while (true) {
      visited.insert(i * n + j);
      auto cur_dir = grid[i][j];
      // then next
      if (cur_dir == 1) {
        // next valid path
        if (right) {
          j++;

          if (i < 0 || i >= m || j < 0 || j >= n || visited.count(i * n + j)) {
            return false;
          }
          // next valid is only street 3(turn down) or street 5(turn up)
          // include it self
          if (grid[i][j] != 3 && grid[i][j] != 5 && grid[i][j] != 1) {
            return false;
          }

          if (i == m - 1 && j == n - 1) {
            break;
          }
          // turn direction
          if (grid[i][j] == 5) {
            down = false;
          }
          if (grid[i][j] == 3) {
            down = true;
          }
        } else {
          j--;

          if (i < 0 || i >= m || j < 0 || j >= n || visited.count(i * n + j)) {
            return false;
          }
          // next valid is only street 4 or street 6
          if (grid[i][j] != 4 && grid[i][j] != 6 && grid[i][j] != 1) {
            return false;
          }

          if (i == m - 1 && j == n - 1) {
            break;
          }
          // turn direction to up
          if (grid[i][j] == 6) {
            down = false;
          }
          if (grid[i][j] == 4) {
            down = true;
          }
        }
      } else if (cur_dir == 2) {
        if (down) {
          i++;
          if (i < 0 || i >= m || j < 0 || j >= n || visited.count(i * n + j)) {
            return false;
          }
          if (grid[i][j] != 5 && grid[i][j] != 6 && grid[i][j] != 2) {
            return false;
          }

          if (i == m - 1 && j == n - 1) {
            break;
          }
          // turn direction!
          if (grid[i][j] == 5) {
            right = false;
          }
          if (grid[i][j] == 6) {
            right = true;
          }
        } else {
          i--;
          if (i < 0 || i >= m || j < 0 || j >= n || visited.count(i * n + j)) {
            return false;
          }
          if (grid[i][j] != 3 && grid[i][j] != 4 && grid[i][j] != 2) {
            return false;
          }

          if (i == m - 1 && j == n - 1) {
            break;
          }
          // turn direction
          if (grid[i][j] == 3) {
            right = false;
          }
          if (grid[i][j] == 4) {
            right = true;
          }
        }
      } else if (cur_dir == 3) {
        if (right) {
          i++;

          if (i < 0 || i >= m || j < 0 || j >= n || visited.count(i * n + j)) {
            return false;
          }
          // ensure down
          down = true;
          if (grid[i][j] != 5 && grid[i][j] != 6 && grid[i][j] != 2) {
            return false;
          }

          if (i == m - 1 && j == n - 1) {
            break;
          }

          if (grid[i][j] == 5) {
            right = false;
          }
          if (grid[i][j] == 6) {
            right = true;
          }
          // street2 just flow , don't change direction
        } else {
          j--;

          if (i < 0 || i >= m || j < 0 || j >= n || visited.count(i * n + j)) {
            return false;
          }
          // ensure left
          right = false;

          if (grid[i][j] != 1 && grid[i][j] != 4 && grid[i][j] != 6) {
            return false;
          }

          if (i == m - 1 && j == n - 1) {
            break;
          }
          if (grid[i][j] == 4) {
            down = true;
          }
          if (grid[i][j] == 6) {
            down = false;
          }
        }
      } else if (cur_dir == 4) {
        // from bottom to right
        if (!down) {
          j++;
          if (i < 0 || i >= m || j < 0 || j >= n || visited.count(i * n + j)) {
            return false;
          }
          // ensure right
          right = true;
          if (grid[i][j] != 1 && grid[i][j] != 3 && grid[i][j] != 5) {
            return false;
          }

          if (i == m - 1 && j == n - 1) {
            break;
          }
          if (grid[i][j] == 3) {
            down = true;
          }
          if (grid[i][j] == 5) {
            down = false;
          }
        } else {
          i++;

          if (i < 0 || i >= m || j < 0 || j >= n || visited.count(i * n + j)) {
            return false;
          }
          // ensure down
          down = true;
          if (grid[i][j] != 2 && grid[i][j] != 5 && grid[i][j] != 6) {
            return false;
          }

          if (i == m - 1 && j == n - 1) {
            break;
          }
          if (grid[i][j] == 5) {
            right = false;
          }
          if (grid[i][j] == 6) {
            right = true;
          }
        }
      } else if (cur_dir == 5) {
        if (right) {
          i--;
          if (i < 0 || i >= m || j < 0 || j >= n || visited.count(i * n + j)) {
            return false;
          }
          // ensure
          down = false;
          if (grid[i][j] != 3 && grid[i][j] != 4 && grid[i][j] != 2) {
            return false;
          }

          if (i == m - 1 && j == n - 1) {
            break;
          }

          if (grid[i][j] == 3) {
            right = false;
          }
          if (grid[i][j] == 4) {
            right = true;
          }

        } else {
          j--;

          if (i < 0 || i >= m || j < 0 || j >= n || visited.count(i * n + j)) {
            return false;
          }

          right = false;

          if (grid[i][j] != 1 && grid[i][j] != 4 && grid[i][j] != 6) {
            return false;
          }

          if (i == m - 1 && j == n - 1) {
            break;
          }

          if (grid[i][j] == 4) {
            down = true;
          }
          if (grid[i][j] == 6) {
            down = false;
          }
        }
      } else if (cur_dir == 6) {
        if (down) {
          j++;

          if (i < 0 || i >= m || j < 0 || j >= n || visited.count(i * n + j)) {
            return false;
          }
          right = true;
          if (grid[i][j] != 1 && grid[i][j] != 3 && grid[i][j] != 5) {
            return false;
          }

          if (i == m - 1 && j == n - 1) {
            break;
          }

          if (grid[i][j] == 3) {
            down = true;
          }
          if (grid[i][j] == 5) {
            down = false;
          }
        }
      }
    }

    return true;
  }
#endif
};

int main() {
  Solution so;
  vector<vector<int>> input{{4, 1, 3}, {6, 1, 2}};
  auto ret = so.hasValidPath(input);
  cout << ret << endl;
}
