// http://leetcode.com/problems/construct-quad-tree/description/
#include "xxx.h"

class QNode {
public:
  bool val;
  bool isLeaf;
  QNode *topLeft;
  QNode *topRight;
  QNode *bottomLeft;
  QNode *bottomRight;

  QNode() {}

  QNode(bool _val, bool _isLeaf, QNode *_topLeft, QNode *_topRight,
        QNode *_bottomLeft, QNode *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

// replace QNode ==> Node before commit to leetcode
class Solution {
public:
  QNode *construct(vector<vector<int>> &grid) {
    return build(grid, 0, 0, grid.size());
  }

private:
  QNode *build(vector<vector<int>> &grid, int x, int y, int len) {
    if (len < 0) {
      return nullptr;
    }
    for (int i = x; i < x + len; ++i) {
      for (int j = y; j < y + len; ++j) {
        // 需要分区
        if (grid[i][j] != grid[x][y]) {
          return new QNode(true /*whatever*/, false, build(grid, x, y, len / 2),
                           build(grid, x, y + len / 2, len / 2),
                           build(grid, x + len / 2, y, len / 2),
                           build(grid, x + len / 2, y + len / 2, len / 2));
        }
      }
    }

    // ==0
    return new QNode(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
  }
};
