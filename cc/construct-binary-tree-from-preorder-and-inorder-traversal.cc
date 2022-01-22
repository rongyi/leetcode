// http://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || preorder.size() != inorder.size()) {
      return nullptr;
    }
    TreeNode *root;
    dobuild(root, preorder, inorder, inorder.size(), 0, 0);
    return root;
  }

private:
  void dobuild(TreeNode *&root, vector<int> &preorder, vector<int> &inorder,
               int size, int pidx, int iidx) {
    if (iidx >= size) {
      return;
    }
    root = new TreeNode(preorder[pidx]);
    int cur_in;
    for (int i = 0; i < size; i++) {
      if (inorder[i] == preorder[pidx]) {
        cur_in = i;
        break;
      }
    }

    dobuild(root->left, preorder, inorder, cur_in, pidx + 1, iidx);

    dobuild(root->right, preorder, inorder, size, pidx + cur_in - iidx + 1,
            cur_in + 1);
  }
};
