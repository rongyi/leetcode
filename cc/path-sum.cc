// http://leetcode.com/problems/path-sum/description/
#include "xxx.h"

class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root) {
      return false;
    }
    unordered_set<int> sums;
    dfs(root, sums, 0);
    return sums.find(sum) != sums.end();
  }
  void dfs(TreeNode *root, unordered_set<int> &sums, int cur) {
    if (!root) {
      return;
    }
    // check a leaf
    if (!root->left && !root->right) {
      sums.insert(cur + root->val);
      return;
    }
    dfs(root->left, sums, cur + root->val);
    dfs(root->right, sums, cur + root->val);
  }
};
