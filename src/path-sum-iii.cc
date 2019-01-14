// http://leetcode.com/problems/path-sum-iii/description/
#include "xxx.h"

class Solution {
public:
  int pathSum(TreeNode *root, int sum) {
    if (!root) {
      return 0;
    }

    return dfs(root, sum, 0) + pathSum(root->left, sum) +
           pathSum(root->right, sum);
  }

private:
  int dfs(TreeNode *root, const int target, int cur) {
    if (!root) {
      return 0;
    }
    // plus current node
    cur += root->val;
    if (cur == target) {
      return 1 + dfs(root->left, target, cur) + dfs(root->right, target, cur);
    }
    return dfs(root->left, target, cur) + dfs(root->right, target, cur);
  }
};
