// http://leetcode.com/problems/sum-root-to-leaf-numbers/description/
#include "xxx.hpp"

class Solution {
public:
  int sumNumbers(TreeNode *root) {
    vector<int> lc;

    recur(root, 0, lc);

    return accumulate(lc.begin(), lc.end(), 0);
  }

private:
  void recur(TreeNode *root, int cur_sum, vector<int> &lc) {
    if (!root) {
      return;
    }
    if (!root->left && !root->right) {
      lc.push_back(cur_sum * 10 + root->val);
      return;
    }
    recur(root->left, cur_sum * 10 + root->val, lc);
    recur(root->right, cur_sum * 10 + root->val, lc);
  }
};
