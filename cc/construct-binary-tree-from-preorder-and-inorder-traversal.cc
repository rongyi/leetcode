// http://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    root_idx_ = 0;

    return do_build(preorder, inorder, 0, inorder.size() - 1);
  }

private:
  TreeNode *do_build(vector<int> &preorder, vector<int> &inorder, int l,
                     int r) {
    if (l > r) {
      return nullptr;
    }

    int i = l;
    for (; i <= r; i++) {
      if (inorder[i] == preorder[root_idx_]) {
        break;
      }
    }

    root_idx_++;
    TreeNode *cur = new TreeNode(inorder[i]);
    cur->left = do_build(preorder, inorder, l, i - 1);
    cur->right = do_build(preorder, inorder, i + 1, r);

    return cur;
  }

private:
  int root_idx_;
};
