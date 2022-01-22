// http://leetcode.com/problems/balance-a-binary-search-tree/description/
#include "xxx.hpp"

class Solution {
public:
  // 重建貌似比较方便
  TreeNode *balanceBST(TreeNode *root) {
    inOrder(root);
    return reconstruct(0, sorted_.size() - 1);
  }

private:
  void inOrder(TreeNode *root) {
    if (!root) {
      return;
    }
    inOrder(root->left);
    sorted_.push_back(root);
    inOrder(root->right);
  }
  TreeNode *reconstruct(int start, int end) {
    if (start > end) {
      return nullptr;
    }
    auto mid = start + (end - start) / 2;
    TreeNode *ret = sorted_[mid];
    ret->left = reconstruct(start, mid - 1);
    ret->right = reconstruct(mid + 1, end);

    return ret;
  }

private:
  vector<TreeNode *> sorted_;
};
