// http://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
#include "xxx.hpp"

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
    // 找到当前根节点在中序中的位置
    // 这个位置劈开，左边到iidex就是左子树的节点
    // 右边到pi - 1都是右子树的节点
    int cur_in;
    for (int i = iidx; i < size; i++) {
      if (inorder[i] == postorder[pi]) {
        cur_in = i;
        break;
      }
    }

    // 差代表着右半边的数量的多少, 减去等于对应另一半
    //       1
    //      2  3
    //    4   5
    // post ==> 4 5 2 3 1
    // in ==>   2 2 5 1 3
    // 算2的在post中的位置: 右子树包括根节点的个数 (size - cur_in) == 2
    // post 中对应从pi偏移这么多即可
    doBuild(root->left, postorder, inorder, pi - (size - cur_in), iidx, cur_in);
    // 右子树顺在post order中紧挨着根节点
    doBuild(root->right, postorder, inorder, pi - 1, cur_in + 1, size);
  }
};
