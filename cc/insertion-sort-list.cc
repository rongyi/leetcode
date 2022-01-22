// http://leetcode.com/problems/insertion-sort-list/description/
#include "xxx.hpp"

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (!head) {
      return nullptr;
    }

    ListNode dummy(-1);
    ListNode *cur = &dummy;
    auto *p = head;
    while (p) {
      auto *next = p->next;
      cur = &dummy;
      while (cur->next && cur->next->val < p->val) {
        cur = cur->next;
      }
      // chain together
      p->next = cur->next;
      cur->next = p;

      p = next;
    }

    return dummy.next;
  }
};
