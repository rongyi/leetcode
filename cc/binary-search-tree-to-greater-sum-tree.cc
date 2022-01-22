// http://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *bstToGst(TreeNode *root) {
    inorder(root, 0);
    return root;
  }

private:
  int inorder(TreeNode *root, int right_sum) {
    if (!root) {
      return right_sum;
    }
    auto sum = inorder(root->right, right_sum);
    root->val += sum;

    inorder(root->left, root->val);

    // if (root->left) {
    //   return root->left->val;
    // }
    // return root->val;

    // 返回最左节点的那个值
    TreeNode *p = root;
    while (p->left) {
      p = p->left;
    }
    return p->val;
  }
};
