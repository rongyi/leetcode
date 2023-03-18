// http://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
#include "xxx.hpp"

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
  Node *connect(Node *root) {

    if (!root) {
      return nullptr;
    }
    Node ret(-1);
    // for next level
    Node *tail = &ret;

    for (Node *cur = root; cur; cur = cur->next) {
      if (cur->left) {
        tail->next = cur->left;
        tail = tail->next;
      }
      if (cur->right) {
        tail->next = cur->right;
        tail = tail->next;
      }
    }

    connect(ret.next);

    return root;
  }
};
