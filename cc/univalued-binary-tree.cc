// http://leetcode.com/problems/univalued-binary-tree/description/
#include "xxx.hpp"

class Solution {
public:
  bool isUnivalTree(TreeNode *root) {
    // node range [1, 100]
    const int value = root->val;
    return check(root, value);
  }
  bool check(TreeNode *root, int value) {
    // 空不是问题，就是不能相等
    if (!root) {
      return true;
    }
    if (root->val != value) {
      return false;
    }
    return check(root->left, value) && check(root->right, value);
  }
};
