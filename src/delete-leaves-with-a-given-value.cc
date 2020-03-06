// http://leetcode.com/problems/delete-leaves-with-a-given-value/description/
#include "xxx.h"

class Solution {
public:
  TreeNode *removeLeafNodes(TreeNode *root, int target) {
    // just make dummy different with target
    TreeNode dummy(target - 1);
    dummy.left = root;
    TreeNode *p = &dummy;
    dfs(root, target, p, true);

    return dummy.left;
  }

private:
  // bring parent down to tree
  void dfs(TreeNode *root, int target, TreeNode *&parent, bool is_left) {
    if (!root) {
      return;
    }
    dfs(root->left, target, root, true);
    dfs(root->right, target, root, false);
    if (!root->left && !root->right && (root->val == target)) {
      if (is_left) {
        parent->left = nullptr;
      } else {
        parent->right = nullptr;
      }
    }
  }
};
