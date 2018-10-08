// http://leetcode.com/problems/reverse-linked-list-ii/description/
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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head) {
      return nullptr;
    }
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *prev = &dummy;
    for (int i = 0; i < m - 1; ++i) {
      prev = prev->next;
    }
    ListNode *const head2 = prev;
    // 三个循环迭代
    prev = head2->next;
    ListNode *cur = prev->next;
    // head2 -> prev -> cur
    // 采用头插法置换
    for (int i = m; i < n; ++i) {
      prev->next = cur->next;
      cur->next = head2->next;
      head2->next = cur;

      cur = prev->next;
    }

    return dummy.next;
  }
};
