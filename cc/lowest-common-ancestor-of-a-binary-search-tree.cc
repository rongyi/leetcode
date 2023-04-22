// http://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
#include "xxx.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> pathp;
    vector<TreeNode *> pathq;
    find(root, p, pathp);
    find(root, q, pathq);
    TreeNode *same = root;
    for (int i = 0; i < min(pathp.size(), pathq.size()); i++) {
      if (pathp[i] == pathq[i]) {
        same = pathp[i];
      }
    }

    return same;
  }

private:
  void find(TreeNode *root, TreeNode *t, vector<TreeNode *> &path) {
    if (!root) {
      return;
    }
    path.push_back(root);
    if (t->val < root->val) {
      find(root->left, t, path);
    } else if (t->val > root->val) {
      find(root->right, t, path);
    }
  }
};

class SolutionRecur {
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
