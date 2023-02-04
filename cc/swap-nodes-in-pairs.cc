// http://leetcode.com/problems/leetcode/swap-nodes-in-pairs/description/
#include "xxx.hpp"
/**
 * Definition for singly-linked list.
 */
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == nullptr) {
      return head;
    }
    // two nodes
    ListNode *next_round = head->next->next;
    ListNode ret(-1);
    ListNode *tail = &ret;

    tail->next = head->next;
    tail = tail->next;

    tail->next = head;
    tail = tail->next;
    // head->next = nullptr;
    tail->next = swapPairs(next_round);

    return ret.next;
  }
};

