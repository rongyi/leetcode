// http://leetcode.com/problems/binary-tree-maximum-path-sum/description/
#include "xxx.hpp"

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int ret = numeric_limits<int>::min();

    dfs(root, ret);

    return ret;
  }
  int dfs(TreeNode *root, int &ret) {
    if (!root) {
      return 0;
    }
    // 对于每一个节点都这么来一下
    auto l = dfs(root->left, ret);
    auto r = dfs(root->right, ret);
    auto cur = root->val;
    if (l > 0) {
      cur += l;
    }
    if (r > 0) {
      cur += r;
    }
    ret = max(ret, cur);

    return max(l, r) > 0 ? max(l, r) + root->val : root->val;
  }
};
