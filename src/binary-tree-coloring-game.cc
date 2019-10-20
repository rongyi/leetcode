// http://leetcode.com/problems/binary-tree-coloring-game/description/
#include "xxx.h"

class Solution {
public:
  bool btreeGameWinningMove(TreeNode *root, int n, int x) {
    countNode(root, x);
    // eighter left child of x/right child of x / parent child of x
    return lcount_ > n / 2 || rcount_ > n / 2 || lcount_ + rcount_ < n / 2;
  }
  int countNode(TreeNode *root, int x) {
    if (!root) {
      return 0;
    }

    auto l = countNode(root->left, x);
    auto r = countNode(root->right, x);

    if (root->val == x) {
      lcount_ = l;
      rcount_ = r;
    }

    return 1 + l + r;
  }

private:
  int lcount_;
  int rcount_;
};
