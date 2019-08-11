// http://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
#include "xxx.h"

class Solution {
public:
  int maxAncestorDiff(TreeNode *root) {
    return dfs(root, 0, 100000);
  }
  int dfs(TreeNode *root, int cur_max, int cur_min) {
    if (!root) {
      return cur_max - cur_min;
    }
    cur_max = max(cur_max, root->val);
    cur_min = min(cur_min, root->val);
    return max(dfs(root->left, cur_max, cur_min), dfs(root->right, cur_max, cur_min));
  }
};
