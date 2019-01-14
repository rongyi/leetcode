// http://leetcode.com/problems/balanced-binary-tree/description/
#include "xxx.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (!root) {
      return true;
    }
    auto hleft = maxDepth(root->left);
    auto hright = maxDepth(root->right);
    if (abs(hright - hleft) > 1) {
      return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
  }

private:
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    auto left = maxDepth(root->left);
    auto right = maxDepth(root->right);
    return max(left, right) + 1;
  }
};
