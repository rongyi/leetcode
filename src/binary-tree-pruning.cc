// http://www.lintcode.com/zh-cn/problem/binary-tree-pruning
#include "one.h"


// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* pruneTree(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->val == 0 && root->left == nullptr  && root->right == nullptr) {
      delete root;
      return nullptr;
    }
    return root;
  }
};
