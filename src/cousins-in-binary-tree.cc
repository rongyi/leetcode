// http://leetcode.com/problems/cousins-in-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  bool isCousins(TreeNode *root, int x, int y) {
    int hx = 0;
    found(root, x, hx);
    int hy = 0;
    found(root, y, hy);

    if (hx != hy) {
      return false;
    }

    if (singleParent(root, x, y)) {
      return false;
    }

    return true;
  }
  bool singleParent(TreeNode *root, int x, int y) {
    if (!root) {
      return false;
    }
    if (root->left && root->right) {
      if (root->left->val == x && root->right->val == y) {
        return true;
      }
      if (root->left->val == y && root->right->val == x) {
        return true;
      }
    }
    return singleParent(root->left, x, y) || singleParent(root->right, x, y);
  }

  bool found(TreeNode *root, int x, int &cur_height) {
    if (!root) {
      return false;
    }
    if (root->val == x) {
      return true;
    }
    ++cur_height;
    int origin = cur_height;
    if (found(root->left, x, cur_height)) {
      return true;
    }
    cur_height = origin;
    return found(root->right, x, cur_height);
  }
};
