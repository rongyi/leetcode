// http://leetcode.com/problems/print-binary-tree/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<string>> printTree(TreeNode *root) {
    auto h = height(root);
    auto w = pow(2, h) - 1;
    vector<vector<string>> ret(h, vector<string>(w, ""));
    recur(root, ret, 0, 0, w - 1);
    return ret;
  }
private:
  int height(TreeNode *root) {
    if (!root) {
      return 0;
    }
    auto hl = height(root->left);
    auto hr = height(root->right);
    return max(hl, hr) + 1;
  }
  int width(TreeNode *root) {
    if (!root) {
      return 0;
    }
    auto wl = width(root->left);
    auto wr = width(root->right);
    return max(wl, wr) * 2 + 1;
  }
  void recur(TreeNode *root, vector<vector<string>> &ret, int level, int l,
             int r) {
    if (!root) {
      return;
    }
    auto mid = l + (r - l) / 2;
    ret[level][mid] = to_string(root->val);
    recur(root->left, ret, level + 1, l, mid - 1);
    recur(root->right, ret, level + 1, mid + 1, r);
  }
};
