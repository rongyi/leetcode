// http://leetcode.com/problems/add-two-numbers/description/
#include "one.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    auto p1 = l1;
    auto p2 = l2;
    ListNode *ret = nullptr;
    ListNode *cur = nullptr;
    while (p1 && p2) {
      auto sum = p1->val + p2->val + carry;
      carry = sum / 10;
      sum %= 10;
      ListNode *new_node = new ListNode(sum);
      if (cur == nullptr) {
        cur = new_node;
        ret = cur;
      } else {
        cur->next = new_node;
        cur = cur->next;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    // only one will be exec
    while (p1) {
      auto sum = p1->val + carry;
      carry = sum / 10;
      sum %= 10;
      ListNode *new_node = new ListNode(sum);
      cur->next = new_node;
      cur = cur->next;
      p1 = p1->next;
    }

    while (p2) {
      auto sum = p2->val + carry;
      carry = sum / 10;
      sum %= 10;
      ListNode *new_node = new ListNode(sum);
      cur->next = new_node;
      cur = cur->next;
      p2 = p2->next;
    }
    if (carry > 0) {
      ListNode *new_node = new ListNode(carry);
      cur->next = new_node;
      cur = cur->next;
    }
    return ret;
  }
};
