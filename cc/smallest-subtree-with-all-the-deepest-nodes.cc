// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
#include "xxx.h"

class Solution {
public:
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    auto l = depth(root->left);
    auto r = depth(root->right);
    if (l == r) {
      return root;
    } else if (l > r) {
      return subtreeWithAllDeepest(root->left);
    }
    return subtreeWithAllDeepest(root->right);
  }
  int depth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    auto left = depth(root->left);
    auto right = depth(root->right);

    return max(left, right) + 1;
  }
};
