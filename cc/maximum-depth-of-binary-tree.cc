// http://leetcode.com/problems/maximum-depth-of-binary-tree/description/
#include "xxx.hpp"

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
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return max(l, r) + 1;
  }
};
