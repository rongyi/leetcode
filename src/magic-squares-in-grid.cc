// http://leetcode.com/problems/magic-squares-in-grid/description/
#include "xxx.h"

class Solution {
public:
  // 又被喷的一逼
  int numMagicSquaresInside(vector<vector<int>> &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ret = 0;
    for (int i = 0; i < m - 2; i++) {
      for (int j = 0; j < n - 2; j++) {
        if (valid(grid, i, j)) {
          ret++;
        }
      }
    }
    return ret;
  }

private:
  bool valid(vector<vector<int>> &grid, int x, int y) {
    // fast path
    if (grid[x + 1][y + 1] != 5) {
      return false;
    }
    // num uniq check
    unordered_set<int> uniq;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        uniq.insert(grid[x + i][y + j]);
      }
    }
    if (uniq.size() != 9) {
      return false;
    }
    for (int i = 1; i <= 9; i++) {
      uniq.erase(i);
    }
    if (!uniq.empty()) {
      return false;
    }

    // sum check
    for (int i = 0; i < 3; i++) {
      if (grid[x + i][y] + grid[x + i][y + 1] + grid[x + i][y + 2] != 15) {
        return false;
      }
    }

    for (int j = 0; j < 3; j++) {
      if (grid[x][y + j] + grid[x + 1][y + j] + grid[x + 2][y + j] != 15) {
        return false;
      }
    }
    //
    if (grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2] != 15) {
      return false;
    }
    if (grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y] != 15) {
      return false;
    }
    return true;
  }
};

int main() {
  Solution so;
  // [[3,2,9,2,7],[6,1,8,4,2],[7,5,3,2,7],[2,9,4,9,6],[4,3,8,2,5]]
  vector<vector<int>> input{{3, 2, 9, 2, 7},
                            {6, 1, 8, 4, 2},
                            {7, 5, 3, 2, 7},
                            {2, 9, 4, 9, 6},
                            {4, 3, 8, 2, 5}};
  so.numMagicSquaresInside(input);
}
