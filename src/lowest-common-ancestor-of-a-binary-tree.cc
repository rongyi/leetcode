// http://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
#include "simpleone.h"

class Solution {
public:
  // 与之前题目不一样的是： 这只是二叉树，而不是BST
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // p and q are different and both values will exist in this binary tree
    if (p == root) {
      return p;
    }
    if (q == root) {
      return q;
    }
    bool p_at_left = false;
    bool q_at_left = false;
    find(root->left, p, q, p_at_left, q_at_left);
    if (p_at_left ^ q_at_left) {
      return root;
    }
    if (p_at_left && q_at_left) {
      return lowestCommonAncestor(root->left, p, q);
    }
    return lowestCommonAncestor(root->right, p, q);
  }

private:
  // target is not null
  void find(TreeNode *root, TreeNode *p, TreeNode *q, bool &pfound,
            bool &qfound) {
    if (!root) {
      return;
    }
    if (root == p) {
      pfound = true;
    }
    if (root == q) {
      qfound = true;
    }

    if (pfound && qfound) {
      return;
    }

    find(root->left, p, q, pfound, qfound);
    find(root->right, p, q, pfound, qfound);
  }
};
