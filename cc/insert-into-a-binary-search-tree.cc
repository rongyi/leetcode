// http://leetcode.com/problems/insert-into-a-binary-search-tree/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) {
      return new TreeNode(val);
    }
    TreeNode *node = new TreeNode(val);
    do_insert(root, node);

    return root;
  }

private:
  // node is node to be inserted to bst
  // which root is hold by root
  void do_insert(TreeNode *root, TreeNode *node) {
    if (!root) {
      return;
    }
    if (node->val < root->val) {
      if (!root->left) {
        root->left = node;
        return;
      }
      do_insert(root->left, node);
    } else {
      if (!root->right) {
        root->right = node;
        return;
      }
      do_insert(root->right, node);
    }
  }
};
