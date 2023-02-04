// http://leetcode.com/problems/reverse-nodes-in-k-group/description/
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
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1) {
      return head;
    }
    if (head == nullptr) {
      return head;
    }
    int i = k;
    ListNode *p = head;
    ListNode *prev = nullptr;
    while (p && i) {
      prev = p;
      p = p->next;
      i--;
    }
    if (i != 0) {
      return head;
    }
    // full k group
    ListNode *next_round = prev->next;
    prev->next = nullptr;

    ListNode ret(-1);
    p = head;
    ListNode *tail = head;
    while (p) {
      ListNode *tmp = p->next;
      p->next = ret.next;
      ret.next = p;

      p = tmp;
    }
    tail->next = reverseKGroup(next_round, k);

    return ret.next;
  }
};
