// https://leetcode.com/problems/symmetric-tree/
#include "xxx.hpp"

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }
    return isSymmetricChild(root->left, root->right);
  }

private:
  bool isSymmetricChild(TreeNode *l, TreeNode *r) {
    bool diff = !l ^ !r;
    if (diff) {
      return false;
    }
    if (l == nullptr) {
      return true;
    }
    if (l->val != r->val) {
      return false;
    }

    return isSymmetricChild(l->left, r->right) &&
           isSymmetricChild(l->right, r->left);
  }
};
