// http://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    const int n = preorder.size();

    return construct(preorder, 0, n - 1);
  }

private:
  TreeNode *construct(vector<int> &preorder, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    if (start == end) {
      return new TreeNode(preorder[start]);
    }
    // now ther is a range
    TreeNode *root = new TreeNode(preorder[start]);
    int first_large_idx = -1;
    for (int i = start + 1; i <= end; i++) {
      if (preorder[i] > preorder[start]) {
        first_large_idx = i;
        break;
      }
    }
    if (first_large_idx == -1) {
      root->left = construct(preorder, start + 1, end);
      root->right = nullptr;
    } else {
      root->left = construct(preorder, start + 1, first_large_idx - 1);
      root->right = construct(preorder, first_large_idx, end);
    }

    return root;
  }
};
