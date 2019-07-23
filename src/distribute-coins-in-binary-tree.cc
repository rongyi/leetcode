// http://leetcode.com/problems/distribute-coins-in-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  int distributeCoins(TreeNode *root) {
    int ret = 0;
    dfs(root, ret);

    return ret;
  }
  int dfs(TreeNode *root, int &mv) {
    if (!root) {
      return 0;
    }
    auto l = dfs(root->left, mv);
    auto r = dfs(root->right, mv);
    mv += abs(l) + abs(r);

    return root->val + l + r - 1;
  }
};
