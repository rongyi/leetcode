// http://leetcode.com/problems/same-tree/description/
#include "xxx.hpp"

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p ^ !q) {
      return false;
    }
    if (p == nullptr) {
      return true;
    }
    if (p->val == q->val) {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    return false;
  }
};
