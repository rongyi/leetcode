// http://leetcode.com/problems/leetcode/merge-k-sorted-lists/description/
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }
    ListNode *p = lists[0];
    for (int i = 1; i < lists.size(); ++i) {
      p = mergeTwoLists(p, lists[i]);
    }
    return p;
  }
private:
 ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1);
    ListNode *cur = &dummy;
    auto p1 = l1;
    auto p2 = l2;
    while (p1 && p2) {
      if (p1->val <= p2->val) {
        cur->next = p1;
        p1 = p1->next;
      } else {
        cur->next = p2;
        p2 = p2->next;
      }
      cur = cur->next;
    }
    if (p1) {
      cur->next = p1;
    }
    if (p2) {
      cur->next = p2;
    }

    return dummy.next;
  }
};
