// http://leetcode.com/problems/insertion-sort-list/description/
#include "xxx.hpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    // sorted list chain
    ListNode ret(-1);
    ListNode *cur = head;
    while (cur) {
      ListNode *prev = &ret;
      ListNode *tmp = cur->next;
      while (prev->next && prev->next->val < cur->val) {
        prev = prev->next;
      }
      // 1 3 2
      //     ^
      cur->next = prev->next;
      prev->next = cur;

      cur = tmp;
    }
    return ret.next;
  }
};
