// http://leetcode.com/problems/delete-node-in-a-bst/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root) {
      return nullptr;
    }

    // root node is target
    if (root->val == key) {
      // no child?
      if (!root->left && !root->right) {
        delete (root);
        return nullptr;
      }

      if (!root->left || !root->right) {
        TreeNode *ret = root->left ? root->left : root->right;

        delete (root);
        return ret;
      }

      if (root->left && root->right) {
        TreeNode *p = root->right;
        while (p->left) {
          p = p->left;
        }
        root->val = p->val;
        // 这里耍了个小聪明，只把值改了，然后再做一遍，最终遇到的那个叶子节点会被干掉，因为条件是符合叶子节点的逻辑
        root->right = deleteNode(root->right, root->val);
      }

    } else if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else {
      root->right = deleteNode(root->right, key);
    }

    return root;
  }
};
