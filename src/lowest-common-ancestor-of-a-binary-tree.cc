// http://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  // 与之前题目不一样的是： 这只是二叉树，而不是BST
  // 这个方法能过但是时间比较惨，倒数
  TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
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

  // 这个效率最高
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || p == root || q == root) {
      return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right) {
      return root;
    }
    if (!left) {
      return right;
    }

    return left;
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
