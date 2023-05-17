// http://leetcode.com/problems/odd-even-linked-list/description/
#include "xxx.hpp"

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    // save odd
    ListNode d1(-1);
    ListNode *tail1 = &d1;
    // save even
    ListNode d2(-2);
    ListNode *tail2 = &d2;

    ListNode *p = head;
    while (p) {
      auto *next = p->next;
      // chain odd
      tail1->next = p;
      tail1 = tail1->next;

      // chain even
      tail2->next = next;
      tail2 = tail2->next;

      if (next) {
        p = next->next;
      } else {
        // 意思就是两个两个走，只剩一个的情况下，这个时候就退出
        break;
      }
    }
    tail1->next = d2.next;

    return d1.next;
  }
};
