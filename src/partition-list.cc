// http://leetcode.com/problems/partition-list/description/
#include "one.h"
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
    // split with two group, and then chain greater group after little than group
    ListNode lt(-1);
    ListNode gt(-1);

    auto lcur = &lt;
    auto gcur = &gt;
    while (head) {
      if (head->val < x) {
        lcur->next = head;
        lcur = lcur->next;
      } else {
        gcur->next = head;
        gcur = gcur->next;
      }
      head = head->next;
    }
    // seal
    gcur->next = nullptr;
    // chain together
    lcur->next = gt.next;

    return lt.next;
  }
};
