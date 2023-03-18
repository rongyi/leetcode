// http://leetcode.com/problems/minimum-depth-of-binary-tree/description/
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
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int ret = numeric_limits<int>::max();
    dfs(root, ret, 1);

    return ret;
  }

  void dfs(TreeNode *root, int &ret, int cur) {
    if (!root) {
      return;
    }
    if (root->left == nullptr && root->right == nullptr) {
      ret = min(ret, cur);
    }
    dfs(root->left, ret, cur + 1);
    dfs(root->right, ret, cur + 1);
  }
};
