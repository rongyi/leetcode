// http://leetcode.com/problems/sort-list/description/
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
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *l1 = head;
    ListNode *l2 = prev->next;
    prev->next = nullptr;
    ListNode *sl1 = sortList(l1);
    ListNode *sl2 = sortList(l2);

    return merge(sl1, sl2);
  }

private:
  ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode ret(-1);
    ListNode *tail = &ret;
    while (l1 || l2) {
      if (l1 && l2) {
        if (l1->val < l2->val) {
          tail->next = l1;
          l1 = l1->next;
        } else {
          tail->next = l2;
          l2 = l2->next;
        }
      } else if (l1) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }

      tail = tail->next;
    }
    return ret.next;
  }
};
