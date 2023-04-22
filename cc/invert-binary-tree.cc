// http://leetcode.com/problems/invert-binary-tree/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    TreeNode *l = root->left;
    TreeNode *r = root->right;

    root->left = invertTree(r);
    root->right = invertTree(l);

    return root;
  }
};
