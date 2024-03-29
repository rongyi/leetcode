// http://leetcode.com/problems/add-two-numbers/description/
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode ret(-1);
    ListNode *last = &ret;
    int carry = 0;
    while (l1 || l2) {
      int sum = carry;
      if (l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }
      ListNode *cur = new ListNode(sum % 10);
      carry = sum / 10;
      last->next = cur;
      last = cur;
    }
    if (carry) {
      last->next = new ListNode(1);
    }

    return ret.next;
  }
};
