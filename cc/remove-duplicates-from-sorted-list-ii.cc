// http://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
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
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    ListNode ret(233);
    ListNode *tail = &ret;
    ListNode *prev_tail = nullptr;

    ListNode *p = head;

    while (p) {
      if (p->val == tail->val) {
        tail = prev_tail;
        tail->next = nullptr;
        int val = p->val;
        while (p && p->val == val) {
          p = p->next;
        }
      } else {
        tail->next = p;
        prev_tail = tail;
        tail = tail->next;
        p = p->next;
      }
      // p = p->next;
    }

    return ret.next;
  }
};
