// http://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/
#include "xxx.h"

class Solution {
public:
  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    auto l = countDepth(root->left);
    auto r = countDepth(root->right);
    if (l == r) {
      return root;
    }
    if (l < r) {
      return lcaDeepestLeaves(root->right);
    }

    return lcaDeepestLeaves(root->left);
  }

private:
  int countDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return 1 + max(countDepth(root->left), countDepth(root->right));
  }
};
