// http://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    auto left = maxDepth(root->left);
    auto right = maxDepth(root->right);
    return max(left, right) + 1;
  }
};