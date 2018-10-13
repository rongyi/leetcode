// http://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
#include "one.h"

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

    if (inorder.empty() || inorder.size() != postorder.size())
      return nullptr;
    TreeNode *ret = nullptr;

    doBuild(ret, postorder, inorder, postorder.size() - 1, 0, inorder.size());

    return ret;
  }

private:
  void doBuild(TreeNode *&root, vector<int> &postorder, vector<int> &inorder,
               int pi, int iidx, int size) {
    if (iidx >= size)
      return;
    root = new TreeNode(postorder[pi]);
    int cur_in;
    for (int i = iidx; i < size; i++) {
      if (inorder[i] == postorder[pi]) {
        cur_in = i;
        break;
      }
    }

    // 差代表着左半边或者是右半边的数量的多少, 减去等于对应另一半
    doBuild(root->left, postorder, inorder,
            pi - (size - cur_in), iidx, cur_in);
    // 右子树顺在post order中紧挨着根节点
    doBuild(root->right, postorder, inorder, pi - 1, cur_in + 1,
            size);
  }
};
