// http://leetcode.com/problems/maximum-binary-tree-ii/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
    if (!root || val > root->val) {
      TreeNode *nr = new TreeNode(val);
      nr->left = root;
      return nr;
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
  }
};
