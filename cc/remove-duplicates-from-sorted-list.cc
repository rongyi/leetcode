// http://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
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

    while (head) {
      if (head->val != tail->val) {
        tail->next = head;
        tail = tail->next;
      }
      head = head->next;
    }
    tail->next = nullptr;

    return ret.next;
  }
};

