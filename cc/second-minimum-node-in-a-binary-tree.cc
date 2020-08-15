// http://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  int findSecondMinimumValue(TreeNode *root) {
    if (!root) {
      return -1;
    }
    // 和root不一样即可
    return recur(root, root->val);
  }
  int recur(TreeNode *root, int first) {
    if (!root) {
      return -1;
    }
    if (root->val != first) {
      return root->val;
    }
    auto left = recur(root->left, first);
    auto right = recur(root->right, first);
    if (left == -1) {
      return right;
    }
    if (right == -1) {
      return left;
    }
    return min(left, right);
  }
};
