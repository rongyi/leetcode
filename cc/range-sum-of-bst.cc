// http://leetcode.com/problems/range-sum-of-bst/description/
#include "xxx.hpp"

class Solution {
public:
  int rangeSumBST(TreeNode *root, int L, int R) {
    int ret = 0;
    recur(root, L, R, ret);

    return ret;
  }

  void recur(TreeNode *root, int L, int R, int &ret) {
    if (!root) {
      return;
    }
    if (root->val >= L && root->val <= R) {
      ret += root->val;
    }
    if (L < root->val) {
      recur(root->left, L, R, ret);
    }
    if (root->val < R) {
      recur(root->right, L, R, ret);
    }
  }
};
