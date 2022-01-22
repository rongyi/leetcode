// http://leetcode.com/problems/same-tree/description/
#include "xxx.hpp"

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // are all empty tree
    if (p == nullptr && q == nullptr) {
      return true;
    }
    // either one is empty
    if (p == nullptr || q == nullptr) {
      return false;
    }
    // value not equal
    if (p->val != q->val) {
      return false;
    }

    // either have left or have no left
    if (!p->left ^ !q->left) {
      return false;
    }
    // eighter have right or have no right
    if (!p->right ^ !q->right) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
