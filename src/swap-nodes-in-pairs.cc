// http://leetcode.com/problems/leetcode/swap-nodes-in-pairs/description/
#include "one.h"
/**
 * Definition for singly-linked list.
 */
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    if (head->next == nullptr) {
      return head;
    }
    // now we have a pair
    ListNode dummy(-1);
    // save
    auto nexround = head->next->next;
    auto p = head;
    auto q = head->next;
    dummy.next = q;
    q->next = p;
    p->next = swapPairs(nexround);

    return dummy.next;
  }
};
int main() {
  Solution so;
  ListNode l1(1), l2(2), l3(3), l4(4);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  so.swapPairs(&l1);
}
