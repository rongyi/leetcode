// http://leetcode.com/problems/merge-two-sorted-lists/description/
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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode ret(-1);
    ListNode *tail = &ret;

    while (l1 && l2) {
      if (l1->val <= l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      // update tail
      tail = tail->next;
    }
    // check left, either l1 or l2
    if (l1) {
      tail->next = l1;
    }
    if (l2) {
      tail->next = l2;
    }

    return ret.next;
  }
};
