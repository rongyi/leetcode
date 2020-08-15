// http://leetcode.com/problems/invert-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    auto *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
  }
};
