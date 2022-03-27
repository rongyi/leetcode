// https://leetcode.com/problems/merge-nodes-in-between-zeros/
#include "xxx.hpp"

class Solution {
public:
  // recursive
  ListNode *mergeNodes(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return nullptr;
    }

    ListNode *merp = head->next;
    ListNode *cur = merp;
    int val = 0;
    while (cur && cur->val != 0) {
      val += cur->val;
      cur = cur->next;
    }
    // cur now stop at '0'
    merp->val = val;
    merp->next = mergeNodes(cur);

    return merp;
  }
};
