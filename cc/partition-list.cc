// http://leetcode.com/problems/partition-list/description/
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
  ListNode *partition(ListNode *head, int x) {
    ListNode lt(-1);
    ListNode ge(-1);

    ListNode *ltail = &lt;
    ListNode *gtail = &ge;

    while (head) {
      if (head->val < x) {
        ltail->next = head;
        ltail = ltail->next;
      } else {
        gtail->next = head;
        gtail = gtail->next;
      }

      head = head->next;
    }
    gtail->next = nullptr;
    ltail->next = ge.next;

    return lt.next;
  }
};
