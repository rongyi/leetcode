// http://leetcode.com/problems/sum-of-left-leaves/description/
#include "xxx.h"

class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root) {
      return 0;
    }

    int ret = 0;
    sumleft(root, ret);

    return ret;
  }

private:
  void sumleft(TreeNode *root, int &i) {
    if (!root) {
      return;
    }

    // left node and a leaf
    if (root->left && !root->left->left && !root->left->right) {
      i += root->left->val;
    }

    sumleft(root->left, i);
    sumleft(root->right, i);
  }
};
