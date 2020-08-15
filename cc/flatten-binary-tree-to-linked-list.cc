// http://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
#include "xxx.h"

class Solution {
public:
  void flatten(TreeNode *root) {
    if (!root) {
      return;
    }
    if (root->left) {
      flatten(root->left);
    }
    if (root->right) {
      flatten(root->right);
    }
    // insert left to right before the real right
    // cache real right
    auto *tmp = root->right;
    root->right = root->left;
    root->left = nullptr;
    // now chain the last to real right
    // find the last node
    while (root->right) {
      root = root->right;
    }
    root->right = tmp;
  }


};
