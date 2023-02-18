// http://leetcode.com/problems/rotate-list/description/
#include "xxx.hpp"

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head) {
      return nullptr;
    }
    int sz = len(head);
    k %= sz;
    // fast path
    if (k == 0) {
      return head;
    }
    int step = sz - k;
    ListNode *prev = nullptr;
    ListNode *p = head;
    for (int i = 0; i < step; i++) {
      prev = p;
      p = p->next;
    }
    ListNode *new_head = p;
    // cut from here
    prev->next = nullptr;
    while (p->next) {
      p = p->next;
    }
    p->next = head;

    return new_head;
  }

private:
  int len(ListNode *head) {
    int ret = 0;
    while (head) {
      ret++;
      head = head->next;
    }

    return ret;
  }
};
