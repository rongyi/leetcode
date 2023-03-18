// http://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int sz = postorder.size();
    root_idx_ = sz - 1;

    return do_build(postorder, inorder, 0, sz - 1);
  }

private:
  TreeNode *do_build(vector<int> &postorder, vector<int> &inorder, int l,
                     int r) {
    if (l > r) {
      return nullptr;
    }

    int i = l;
    for (; i <= r; i++) {
      if (inorder[i] == postorder[root_idx_]) {
        break;
      }
    }

    root_idx_--;
    TreeNode *cur = new TreeNode(inorder[i]);
    // order: right first
    cur->right = do_build(postorder, inorder, i + 1, r);
    cur->left = do_build(postorder, inorder, l, i - 1);

    return cur;
  }

private:
  int root_idx_;
};
