// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
#include "xxx.hpp"

class Solution {
public:
  int averageOfSubtree(TreeNode *root) {
    dfs(root);
    return cnt_;
  }

private:
  // nodecnt, valuesum
  array<int, 2> dfs(TreeNode *root) {
    if (!root) {
      return array<int, 2>{0, 0};
    }
    auto left_pair = dfs(root->left);
    auto right_pair = dfs(root->right);

    auto nodecnt = left_pair[0] + right_pair[0] + 1;
    auto nodesum = left_pair[1] + right_pair[1] + root->val;
    if (root->val == nodesum / nodecnt) {
      ++cnt_;
    }

    return array<int, 2>{nodecnt, nodesum};
  }

private:
  int cnt_ = 0;
};
