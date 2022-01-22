// http://leetcode.com/problems/trim-a-binary-search-tree/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *trimBST(TreeNode *root, int L, int R) {
    if (!root) {
      return nullptr;
    }
    // 跨了区间了
    if (root->val < L) {
      // 连带左子树全都小于L了，所以结果就是在右子树上找了
      return trimBST(root->right, L, R);
    }
    if (root->val > R) {
      // 连带右子树全部逗比R大，所以结果就是在左子树上找
      return trimBST(root->left, L, R);
    }
    // 如果在这个区间呢？
    if (root->left) {
      if (root->left->val < L) {
        // 连带左子树的全部左子节点都小，所以全部干掉，
        // 新左子树在以前的左子树的右节点开始找
        root->left = trimBST(root->left->right, L, R);
      } else {
        root->left = trimBST(root->left, L, R);
      }
    }
    if (root->right) {
      // 连带右子树以及全部节点不要了
      if (root->right->val > R) {
        root->right = trimBST(root->right->left, L, R);
      } else {
        root->right = trimBST(root->right, L, R);
      }
    }

    return root;
  }

  // 不能拆了重建那!
  TreeNode *trimBSTReconstruct(TreeNode *root, int L, int R) {
    vector<int> lst;
    inorder(root, lst, L, R);
    if (lst.empty()) {
      return nullptr;
    }

    return construct(lst, 0, lst.size() - 1);
  }

  TreeNode *construct(vector<int> &lst, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    auto mid = start + (end - start) / 2;
    TreeNode *left_child = construct(lst, start, mid - 1);
    TreeNode *parent = new TreeNode(lst[mid]);

    parent->left = left_child;

    parent->right = construct(lst, mid + 1, end);

    return parent;
  }
  void inorder(TreeNode *root, vector<int> &lst, int l, int r) {
    if (!root) {
      return;
    }
    inorder(root->left, lst, l, r);
    if (root->val >= l && root->val <= r) {
      lst.push_back(root->val);
    }
    inorder(root->right, lst, l, r);
  }
};
