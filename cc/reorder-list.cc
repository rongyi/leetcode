// http://leetcode.com/problems/reorder-list/description/
#include "xxx.hpp"

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head || !head->next) {
      return;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode r(-1);
    ListNode *p = slow;
    while (p) {
      ListNode *tmp = p->next;
      p->next = r.next;
      r.next = p;
      p = tmp;
    }

    ListNode *p1 = head;
    ListNode *p2 = r.next;
    ListNode *tmp = nullptr;
    while (p2->next) {
      tmp = p1->next;
      p1->next = p2;
      p1 = tmp;

      tmp = p2->next;
      p2->next = p1;
      p2 = tmp;
    }
  }
};
