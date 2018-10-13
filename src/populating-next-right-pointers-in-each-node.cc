// http://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
#include "one.h"

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root) {
      return;
    }
    if (root->left) {
      root->left->next = root->right;
    }
    // 有桥过去吗？
    if (root->right) {
      root->right->next = root->next ? root->next->left : nullptr;
    }
    connect(root->left);
    connect(root->right);
  }
};
