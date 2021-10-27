// https://leetcode.com/problems/cyclically-rotating-a-grid/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int layer = min(m, n) / 2;
    for (int l = 0; l < layer; ++l) {
      // put cur layer in q and rotate
      deque<int> q;
      int curRotation = k % (getPeriod(m, n, l));
      int top_left_x = 0 + l;
      int top_left_y = 0 + l;

      int top_right_x = 0 + l;
      int top_right_y = n - 1 - l;

      int bottom_left_x = m - 1 - l;
      int bottom_left_y = 0 + l;

      int bottom_right_x = m - 1 - l;
      int bottom_right_y = n - 1 - l;

      // collect the element to q
      // left side column top -> down
      for (int i = top_left_x; i <= bottom_left_x; ++i) {
        q.push_back(grid[i][top_left_y]);
      }
      // collect bottom row left -> right
      for (int j = bottom_left_y + 1; j <= bottom_right_y; ++j) {
        q.push_back(grid[bottom_left_x][j]);
      }
      // collect right side column: down -> top
      for (int i = bottom_right_x - 1; i >= top_right_x; --i) {
        q.push_back(grid[i][bottom_right_y]);
      }
      // collect top row, from right to left
      for (int j = top_right_y - 1; j > top_left_y; --j) {
        q.push_back(grid[top_left_x][j]);
      }

      // let's roate, note the order
      // put the end to front
      while (curRotation--) {
        auto back = q.back();
        q.pop_back();
        q.push_front(back);
      }

      for (int i = top_left_x; i <= bottom_left_x; ++i) {
        grid[i][top_left_y] = q.front();
        q.pop_front();
      }
      // please mind the intersection point
      // the elements at those point are collected only once
      // collect bottom row left -> right
      for (int j = bottom_left_y + 1; j <= bottom_right_y; ++j) {
        grid[bottom_left_x][j] = q.front();
        q.pop_front();
      }
      // collect right side column: down -> top
      for (int i = bottom_right_x - 1; i >= top_right_x; --i) {
        grid[i][bottom_right_y] = q.front();
        q.pop_front();
      }
      // collect top row, from right to left
      for (int j = top_right_y - 1; j > top_left_y; --j) {
        grid[top_left_x][j] = q.front();
        q.pop_front();
      }
      // now put to grid again

      // debug code
      // while (!q.empty()) {
      //   cout << q.front() << " ";
      //   q.pop_front();
      // }
      // cout << endl;
    }

    return grid;
  }

public:
  // m: the matrix totoal row
  // n: .. colum
  // layer index, the most outer index is 0
  int getPeriod(int m, int n, int l) {
    int row = m - 2 * l;
    int col = n - 2 * l;
    return (row - 2) * 2 + (col - 2) * 2 + 4;
  }
};

int main() {
  Solution so;
  // cout << so.getPeriod(6, 6, 0) << endl;
  // cout << so.getPeriod(6, 6, 1) << endl;
  // cout << so.getPeriod(2, 2, 0) << endl;

  vector<vector<int>> input{{1, 2, 3, 4},  {16, 1, 2, 5}, {15, 8, 3, 6},
                            {14, 7, 4, 7}, {13, 6, 5, 8}, {12, 11, 10, 9}};
  so.rotateGrid(input, 1);
}
