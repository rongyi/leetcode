// http://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
#include "xxx.hpp"


class Solution {
public:

  void connect(TreeLinkNode *root) {
    if (!root) {
      return;
    }
    TreeLinkNode dummy(-1);

    TreeLinkNode *cur = nullptr;
    TreeLinkNode *prev = &dummy;

    // 在这里过桥，桥在上一层遍历时被修好
    for (cur = root; cur; cur = cur->next) {
      if (cur->left) {
        // 这里修桥，为下一层遍历准备
        prev->next = cur->left;
        prev = prev->next;
      }
      if (cur->right) {
        // 这里修桥
        prev->next = cur->right;
        prev = prev->next;
      }
    }
    // 显然就是下一层的第一个节点
    connect(dummy.next);
  }
};
