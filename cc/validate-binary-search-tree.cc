// http://leetcode.com/problems/validate-binary-search-tree/description/

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
  bool isValidBST(TreeNode *root) {
    long long left = numeric_limits<long long>::min();
    long long right = numeric_limits<long long>::max();
    return pressure(root, left, right);
  }

private:
  bool pressure(TreeNode *root, long long left, long long right) {
    if (!root) {
      return true;
    }
    return root->val < right && root->val > left &&
           pressure(root->left, left, root->val) &&
           pressure(root->right, root->val, right);
  }
};
