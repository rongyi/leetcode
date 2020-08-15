// http://leetcode.com/problems/binary-tree-cameras/description/
#include "xxx.h"

class Solution {
public:
  int minCameraCover(TreeNode *root) {
    int sum = 0;
    if (dfs(root, sum) == 0) {
      ++sum;
    }

    return sum;
  }
  // 尽量把节点往上放，所以身上没有相机的时候，被照顾到应该只能是子节点来照顾
  // 0: there is no camera at this node, and it's not monitored by camera at
  // either of its children, which means neither of child nodes has camera.
  // 1: there is no camera at this node; however, this node is monitored by at
  // least 1 of its children, which means at least 1 of its children has camera.
  // 2: there is a camera at this node.
  int dfs(TreeNode *root, int &sum) {
    if (!root) {
      return 1;
    }
    int l = dfs(root->left, sum);
    int r = dfs(root->right, sum);
    if (l == 0 || r == 0) {
      ++sum;
      return 2;
    } else if (l == 2 || r == 2) {
      return 1;
    }
    return 0;
  }
};
