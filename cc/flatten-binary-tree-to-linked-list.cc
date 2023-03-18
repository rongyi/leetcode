// http://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
#include "xxx.hpp"

class Solution {
public:
  void flatten(TreeNode *root) {
    while (root) {
      if (root->left) {
        TreeNode *origin_right = root->right;
        TreeNode *right_mod_of_left = rightMost(root->left);

        root->right = root->left;
        root->left = nullptr;
        right_mod_of_left->right = origin_right;
      }

      root = root->right;
    }
  }

private:
  TreeNode *rightMost(TreeNode *cur) {
    while (cur->right) {
      cur = cur->right;
    }
    return cur;
  }
};
