// http://leetcode.com/problems/add-one-row-to-tree/description/
#include "xxx.hpp"
class Solution {
public:
  TreeNode *addOneRow(TreeNode *root, int v, int d) {
    // top root
    if (d == 1) {
      TreeNode *nr = new TreeNode(v);
      nr->left = root;
      return nr;
    }
    // they promise root is not null
    grow(root, v, d, 2);

    return root;
  }

private:
  void grow(TreeNode *root, int v, int d, int cur_level) {
    if (!root) {
      return;
    }
    if (cur_level == d) {
      TreeNode *orig_left = root->left;
      root->left = new TreeNode(v);
      root->left->left = orig_left;

      TreeNode *orig_right = root->right;
      root->right = new TreeNode(v);
      root->right->right = orig_right;

      return;
    }
    grow(root->left, v, d, cur_level + 1);
    grow(root->right, v, d, cur_level + 1);
  }
};
