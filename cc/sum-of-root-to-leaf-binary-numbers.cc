// http://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
#include "xxx.hpp"

class Solution {
public:
  int sumRootToLeaf(TreeNode *root) {
    int ret = 0;
    dfs(root, 0, ret);
    return ret;
  }
private:
  void dfs(TreeNode *root, int cur, int &sum) {
    if (!root) {
      return;
    }
    // a leaf
    if (!root->left && !root->right) {
      sum += (cur | root->val);
      return;
    }
    cur |= root->val;

    dfs(root->left, cur << 1, sum);
    dfs(root->right, cur << 1, sum);
  }
};
