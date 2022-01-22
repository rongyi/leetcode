// http://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
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
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    ListNode dummy(-1);
    auto *prev = &dummy;
    auto *cur = &dummy;
    cur->next = head;
    cur = cur->next;
    auto p = head->next;
    // 总体上两个标签，遇到相同的就回退一下，然后在后续列表中consume掉所有一样的
    while (p) {
      // sorry, we must abann cur node;
      if (p->val == cur->val) {
        auto same = p->val;

        cur = prev;
        cur->next = nullptr;
        // now we consume all p that are equal to current val
        while (p && p->val == same) {
          p = p->next;
        }
      } else {
        cur->next = p;
        prev = cur;
        cur = cur->next;
        p = p->next;
      }
    }
    // seal the end
    cur->next = nullptr;
    return dummy.next;
  }
};
