// http://leetcode.com/problems/leetcode/reverse-linked-list/description/
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
  ListNode *reverseList(ListNode *head) {
    ListNode dummy(-1);
    ListNode *cur = &dummy;
    while (head) {
      auto tmp = head->next;
      head->next = cur->next;
      cur->next = head;

      head = tmp;
    }
    return dummy.next;
  }
};
