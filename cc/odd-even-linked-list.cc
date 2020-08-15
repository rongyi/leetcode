// http://leetcode.com/problems/odd-even-linked-list/description/
#include "xxx.h"

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    // save odd
    ListNode d1(-1);
    ListNode *cur1 = &d1;
    // save even
    ListNode d2(-2);
    ListNode *cur2 = &d2;

    ListNode *p = head;
    while (p) {
      auto *next = p->next;
      // chain odd
      cur1->next = p;
      cur1 = cur1->next;

      // chain even
      cur2->next = next;
      cur2 = cur2->next;

      if (next) {
        p = next->next;
      } else {
        // 意思就是两个两个走，只剩一个的情况下，这个时候就退出
        break;
      }
    }
    cur1->next = d2.next;

    return d1.next;
  }
};
