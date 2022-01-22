// http://leetcode.com/problems/flip-equivalent-binary-trees/description/
#include "xxx.hpp"

class Solution {
public:
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    bool has_left_root = !!root1;
    bool has_right_root = !!root2;
    if (has_left_root ^ has_right_root) {
      return false;
    }
    if (!has_left_root && !has_right_root) {
      return true;
    }
    // root val must be equal
    if (root1->val != root2->val) {
      return false;
    }

    // then we check child
    // 传进去的是root，但不是比较root
    return cmp(root1, root2);
  }
  bool cmp(TreeNode *root1, TreeNode *root2) {
    bool has_left1 = !!root1->left;
    bool has_left2 = !!root2->left;

    bool has_righ1 = !!root1->right;
    bool has_righ2 = !!root2->right;
    if (has_left1 && has_righ1) {
      // 要求右边也要有两个全的child
      if (!(has_left2 && has_righ2)) {
        return false;
      }
      // 如果左边相等，必然要求右边也相等
      if (root1->left->val == root2->left->val) {
        if (root1->right->val != root2->right->val) {
          return false;
        }
        // 这一层没有被置换，算下一层
        return cmp(root1->left, root2->left) && cmp(root1->right, root2->right);
      } else {
        // swap了，所以必须要和右边的相等
        if (root1->left->val != root2->right->val) {
          return false;
        }
        if (root1->right->val != root2->left->val) {
          return false;
        }
        // 这一层被换了，所以节点要对调着比较
        return cmp(root1->left, root2->right) && cmp(root1->right, root2->left);
      }
    } else if (has_left1 ^ has_righ1) {
      // 一棵只有一个孩子，那么要求另一颗也是这样
      if (!(has_left2 ^ has_righ2)) {
        return false;
      }
      TreeNode *ltree = nullptr;
      TreeNode *rtree = nullptr;

      if (has_left1) {
        ltree = root1->left;
      } else {
        ltree = root1->right;
      }
      if (has_left2) {
        rtree = root2->left;
      } else {
        rtree = root2->right;
      }
      if (ltree->val != rtree->val) {
        return false;
      }
      return cmp(ltree, rtree);
    }

    // 否则俩树都没孩子，直接返回吧
    return true;
  }
};
