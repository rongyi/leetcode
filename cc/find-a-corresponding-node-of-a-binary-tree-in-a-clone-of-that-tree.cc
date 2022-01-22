// http://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                          TreeNode *target) {
    mirror_ = nullptr;

    recur(original, cloned, target);

    return mirror_;
  }

private:
  void recur(TreeNode *o, TreeNode *c, TreeNode *target) {
    if (!o) {
      return;
    }
    if (target->val == o->val) {
      mirror_ = c;
      return;
    }
    recur(o->left, c->left, target);
    recur(o->right, c->right, target);
  }

private:
  TreeNode *mirror_;
};
