// http://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
#include "xxx.h"

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // p q两个确保不同
    if (p == root) {
      return p;
    }
    if (q == root) {
      return q;
    }
    bool ispleft = p->val < root->val;
    bool isqleft = q->val < root->val;
    // 挂在左右两边共同祖先只能是root
    if (ispleft ^ isqleft) {
      return root;
    }
    // 往一边压下去
    if (ispleft) {
      return lowestCommonAncestor(root->left, p, q);
    }
    return lowestCommonAncestor(root->right, p, q);
  }
};
