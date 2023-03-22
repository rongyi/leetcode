// http://leetcode.com/problems/binary-tree-maximum-path-sum/description/
#include "xxx.hpp"

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    int ret = numeric_limits<int>::min();

    dfs(root, ret);

    return ret;
  }

private:
  int dfs(TreeNode *root, int &ret) {
    if (!root) {
      return 0;
    }

    auto l = dfs(root->left, ret);
    auto r = dfs(root->right, ret);

    auto cur = root->val;
    cur += max(0, l);
    cur += max(0, r);
    ret = max(ret, cur);

    return root->val + max({l, r, 0});
  }
};
