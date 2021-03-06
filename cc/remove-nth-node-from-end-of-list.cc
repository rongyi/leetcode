// http://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
#include "xxx.h"

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head) {
      return nullptr;
    }

    int l = len(head);
    auto left = l - n;
    if (left == 0) {
      auto p = head;
      delete head;
      return p->next;
    }
    auto p = head;
    while (--left) {
      p = p->next;
    }

    auto target = p->next;
    p->next = target->next;
    delete target;

    return head;
  }

private:
  int len(ListNode *head) {
    int ret = 0;
    while (head) {
      ++ret;
      head = head->next;
    }
    return ret;
  }
};
int main() {
  Solution so;
  ListNode l1(1);
  // l1.next = &l2;
  // l2.next = &l3;
  so.removeNthFromEnd(&l1, 1);
}
