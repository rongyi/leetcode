// http://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/description/
#include "xxx.h"

class Solution {
public:
  // When the problem asks for shortest path, BFS should come to mind first.
  int minimumMoves(vector<vector<int>> &grid) {
    int steps = 0;
    queue<array<int, 3>> q1;
    queue<array<int, 3>> q2;
    // 一开始是横着的
    q1.push({0, 0, false});
    while (!q1.empty()) {
      while (!q1.empty()) {
        auto &a = q1.front();
        // 尾巴到位了
        if (a[0] == grid.size() - 1 && a[1] == grid[a[0]].size() - 2) {
          return steps;
        }
        // 访问的标记位， 2表示竖着来过，4表示横着来过
        if ((grid[a[0]][a[1]] & (a[2] ? 2 : 4)) == 0) {
          grid[a[0]][a[1]] |= (a[2] ? 2 : 4);
          if (canGoDown(grid, a[0], a[1], a[2])) {
            q2.push({a[0] + 1, a[1], a[2]});
          }
          if (canGoRight(grid, a[0], a[1], a[2])) {
            q2.push({a[0], a[1] + 1, a[2]});
          }
          if (canRotate(grid, a[0], a[1])) {
            q2.push({a[0], a[1], a[2] ? false : true});
          }
        }
        q1.pop();
      }

      ++steps;
      swap(q1, q2);
    }

    return -1;
  }

private:
  // 四处都为0，下面方法都是以尾巴节点为参照
  bool canRotate(vector<vector<int>> &g, int i, int j) {
    return i < g.size() - 1 && j < g[i].size() - 1 && (g[i + 1][j] & 1) == 0 &&
           (g[i][j + 1] & 1) == 0 && (g[i + 1][j + 1] & 1) == 0;
  }

  bool canGoDown(vector<vector<int>> &g, int i, int j, bool vertical) {
    if (vertical) {
      return i < g.size() - 2 && (g[i + 2][j] & 1) == 0;
    }
    // 横着的，下面两个要为空，这一步是平移
    return i < g.size() - 1 && (g[i + 1][j] & 1) == 0 &&
           (g[i + 1][j + 1] & 1) == 0;
  }
  bool canGoRight(vector<vector<int>> &g, int i, int j, bool vertical) {
    if (!vertical) {
      return j < g[i].size() - 2 && (g[i][j + 2] & 1) == 0;
    }
    //本身是竖着的，右边两个应该为空, 这一步是平移
    return j < g[i].size() - 1 && (g[i][j + 1] & 1) == 0 &&
           (g[i + 1][j + 1] & 1) == 0;
  }
};
