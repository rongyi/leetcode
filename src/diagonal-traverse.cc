// http://leetcode.com/problems/diagonal-traverse/description/
#include "xxx.h"

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    if (m == 0) {
      return {};
    }
    const int n = matrix[0].size();
    if (n == 0) {
      return {};
    }
    vector<int> ret;

    // initial direction is to up
    bool is_up = true;

    // initial start point
    int i = 0;
    int j = 0;

    while (true) {
      if (i < 0 || i >= m || j < 0 || j >= n) {
        break;
      }
      ret.push_back(matrix[i][j]);

      // the next i, j
      int x = 0;
      int y = 0;
      if (is_up) {
        // check valid
        x = i - 1;
        y = j + 1;
        // ouch! we can not go up any more
        // change direction and set x, y
        if (x < 0 || x >= m || y < 0 || y >= n) {
          is_up = false;
          // not to the end
          // move right if possible else move down
          if (j < n - 1) {
            x = i;
            y = j + 1;
          } else {
            x = i + 1;
            y = j;
          }
        }
        // update i, j
        i = x;
        j = y;
      } else {
        // we go down
        x = i + 1;
        y = j - 1;
        // ouch, we can not go down anymore
        if (x < 0 || x >= m || y < 0 || y >= n) {
          is_up = true;
          // move down if possible else move right
          if (i < m - 1) {
            x = i + 1;
            y = j;
          } else {
            // right or else
            x = i;
            y = j + 1;
          }
        }
        // update
        i = x;
        j = y;
      }
      if ((i == m - 1) && (j == n - 1)) {
        ret.push_back(matrix[i][j]);
        break;
      }
    }
    return ret;
  }
};
int main() {
  Solution so;
  // vector<vector<int>> input{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> input{{1}};
  auto ret = so.findDiagonalOrder(input);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
}
