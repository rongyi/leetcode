// http://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
#include "xxx.hpp"

class Solution {
public:
  ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode dummy(0);
    dummy.next = head;

    unordered_map<int, ListNode *> same;
    same[0] = &dummy;
    int acc = 0;
    while (head) {
      acc += head->val;
      if (same.find(acc) != same.end()) {
        auto *prev = same[acc];
        auto *start = prev;

        int tmp = acc;
        while (prev != head) {
          prev = prev->next;
          tmp += prev->val;
          // the special case of consecutive zero
          // is also considered
          if (prev != head) {
            same.erase(tmp);
          }
        }
        start->next = head->next;
      } else {
        same[acc] = head;
      }

      head = head->next;
    }

    return dummy.next;
  }
};
