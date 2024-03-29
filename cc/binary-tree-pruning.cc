// https://leetcode.com/problems/binary-tree-pruning/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *pruneTree(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
      delete root;
      return nullptr;
    }
    return root;
  }
};
