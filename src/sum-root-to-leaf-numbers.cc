// http://leetcode.com/problems/sum-root-to-leaf-numbers/description/
#include "one.h"

class Solution {
public:
  int sumNumbers(TreeNode *root) {
    if (!root) {
      return 0;
    }

    vector<int> leaf_collector;
    dfs(root, 0, leaf_collector);

    return accumulate(leaf_collector.begin(), leaf_collector.end(), 0);
  }

private:
  void dfs(TreeNode *root, int cur_sum, vector<int> &leaf_collector) {
    if (!root) {
      return;
    }
    if (!root->left && !root->right) {
      leaf_collector.push_back(cur_sum * 10 + root->val);
      return;
    }
    if (root->left) {
      dfs(root->left, cur_sum * 10 + root->val, leaf_collector);
    }
    if (root->right) {
      dfs(root->right, cur_sum * 10 + root->val, leaf_collector);
    }
  }
};
