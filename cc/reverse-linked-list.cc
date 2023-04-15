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
    ListNode ret(-1);

    while (head) {
      ListNode *tmp = head->next;
      head->next = ret.next;
      ret.next = head;
      head = tmp;
    }

    return ret.next;
  }
};
