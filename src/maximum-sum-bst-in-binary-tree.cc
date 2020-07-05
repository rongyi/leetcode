// http://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  int maxSumBST(TreeNode *root) {
    max_sum_ = 0;
    dfs(root);
    return max_sum_;
  }

private:
  // {sum, min, max}
  array<int, 3> dfs(TreeNode *node) {
    auto l = node->left ? dfs(node->left)
                        : array<int, 3>{0, node->val, node->val - 1};
    auto r = node->right ? dfs(node->right)
                         : array<int, 3>{0, node->val + 1, node->val};
    // 符合bst规范
    if (l[2] < node->val && node->val < r[1]) {
      max_sum_ = max(max_sum_, node->val + l[0] + r[0]);

      return {node->val + l[0] + r[0], l[1], r[2]};
    }

    return {0, numeric_limits<int>::min(), numeric_limits<int>::max()};
  }

private:
  int max_sum_;
};
