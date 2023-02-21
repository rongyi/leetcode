// http://leetcode.com/problems/rotate-list/description/
#include "xxx.hpp"

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    int sz = len(head);
    if (sz == 0) {
      return nullptr;
    }
    k %= sz;
    if (k == 0) {
      return head;
    }
    // start from head
    int step = sz - k;
    ListNode *prev = nullptr;
    ListNode *p = head;
    for (int i = 0; i < step; i++) {
      prev = p;
      p = p->next;
    }
    ListNode *new_head = p;
    prev->next = nullptr;

    while (p->next) {
      p = p->next;
    }
    p->next = head;

    return new_head;
  }

private:
  int len(ListNode *p) {
    int ret = 0;
    while (p) {
      p = p->next;
      ret++;
    }

    return ret;
  }
};
