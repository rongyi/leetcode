// http://leetcode.com/problems/remove-linked-list-elements/description/
#include "xxx.hpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode ret(-1);
    ListNode *tail = &ret;
    while (head) {
      if (head->val != val) {
        tail->next = head;
        tail = tail->next;
      }
      head = head->next;
    }
    // don't forget the seal
    tail->next = nullptr;

    return ret.next;
  }
};
