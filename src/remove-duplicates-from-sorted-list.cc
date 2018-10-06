// http://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
#include "one.h"

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
    // just make it different with the first node;
    auto val = head->val - 1;
    ListNode dummy(val);
    auto *cur = &dummy;

    auto p = head;
    while (p) {
      // met a uniq element
      if (cur->val != p->val) {
        cur->next = p;
        cur = cur->next;
        p = p->next;
      } else {
        auto n = p->next;
        p->next = nullptr;
        p = n;
      }
    }
    // seal the last
    cur->next = nullptr;
    return dummy.next;
  }
};

int main() {
  Solution so;
  ListNode l1(1), l2(1), l3(2), l4(3), l5(3);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;
  so.deleteDuplicates(&l1);
}
