// http://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
#include "xxx.hpp"

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int sz = len(head);
    n = sz - n;
    if (n == 0) {
      return head->next;
    }
    ListNode *p = head;
    while (--n) {
      p = p->next;
    }
    p->next = p->next->next;
    // delete

    return head;
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
