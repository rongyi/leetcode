// http://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
#include "xxx.hpp"

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
