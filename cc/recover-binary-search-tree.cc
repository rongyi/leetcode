// http://leetcode.com/problems/recover-binary-search-tree/description/
#include "xxx.hpp"

class Solution {
public:
  void recoverTree(TreeNode *root) {
    prev_ = new TreeNode(numeric_limits<int>::min());
    inorder(root);
    swap(first_->val, second_->val);
  }

private:
  void inorder(TreeNode *cur) {
    if (!cur) {
      return;
    }
    inorder(cur->left);
    if (first_ == nullptr && cur->val < prev_->val) {
      first_ = prev_;
    }
    if (first_ != nullptr && cur->val < prev_->val) {
      second_ = cur;
    }

    prev_ = cur;
    inorder(cur->right);
  }

private:
  // [1, 2, 3, 4, 5]
  // [1, 4, 3, 2, 5]
  //     ^
  //           ^
  TreeNode *prev_;
  TreeNode *first_;
  TreeNode *second_;
};
