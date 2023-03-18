// http://leetcode.com/problems/path-sum/description/
#include "xxx.hpp"

class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root) {
      return false;
    }
    found_ = false;

    dfs(root, sum, 0);

    return found_;
  }

private:
  void dfs(TreeNode *root, int sum, int cur) {
    if (!root) {
      return;
    }
    cur += root->val;
    if (cur == sum && root->left == nullptr && root->right == nullptr) {
      found_ = true;
      return;
    }
    dfs(root->left, sum, cur);
    dfs(root->right, sum, cur);
  }

private:
  bool found_;
};
