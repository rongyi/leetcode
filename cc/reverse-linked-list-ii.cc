// http://leetcode.com/problems/reverse-linked-list-ii/description/
#include "xxx.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode ret(-1);
    ret.next = head;
    ListNode *prev = &ret;

    int i = 0;
    for (; i < m - 1; i++) {
      prev = prev->next;
    }
    ListNode *tail = prev->next;
    ListNode *p = prev->next;
    ListNode *next = nullptr;

    while (i < n && p) {
      next = p->next;
      p->next = prev->next;
      prev->next = p;

      p = next;
      i++;
    }
    if (tail) {
      tail->next = next;
    }

    return ret.next;
  }
};
