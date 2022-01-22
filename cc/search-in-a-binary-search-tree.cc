// http://leetcode.com/problems/search-in-a-binary-search-tree/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    if (!root) {
      return nullptr;
    }
    if (root->val == val) {
      return root;
    } else if (val < root->val) {
      return searchBST(root->left, val);
    }
    return searchBST(root->right, val);
  }
};
