// http://leetcode.com/problems/palindrome-linked-list/description/
#include "xxx.hpp"

class Solution {
public:
  // 只能swap咯，没办法的事情
  void deleteNode(ListNode *node) {
    auto *next = node->next;
    node->val = next->val;
    // now we delete next
    node->next = next->next;
    next->next = nullptr;
  }
};
