// http://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/
#include "xxx.hpp"

class Solution {
public:
  // brute force
  vector<int> getBiggestThree(vector<vector<int>> &grid) {
    set<int> s;
    int m = grid.size();
    int n = grid[0].size();
    int len = (min(m, n) >> 1) + 1;

    for (auto &r : grid) {
      for (auto &num : r) {
        s.insert(num);
        if (s.size() > 3) {
          s.erase(s.begin());
        }
      }
    }

    for (int l = 1; l < len; ++l) {
      for (int row = l; row < m - l; row++) {
        for (int col = l; col < n - l; col++) {
          int sum = 0;

          // left to top
          int i = row;
          int j = col - l;
          while (j <= col) {
            sum += grid[i][j];
            i--;
            j++;
          }

          // right to bottom
          i = row;
          j = col + l;
          while (j >= col) {
            sum += grid[i][j];
            i++;
            j--;
          }

          // top to right
          // ignore the corner, which is alredy added
          i = row - l + 1;
          j = col + 1;
          while (i < row) {
            sum += grid[i][j];
            i++;
            j++;
          }

          // bottom to left
          // ignore the corner, which is alredy added
          i = row + l - 1;
          j = col - 1;
          while (i > row) {
            sum += grid[i][j];
            i--;
            j--;
          }

          s.insert(sum);
          if (s.size() > 3) {
            s.erase(s.begin());
          }
        }
      }
    }
    return vector<int>(rbegin(s), rend(s));
  }
};
