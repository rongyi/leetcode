// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
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
  ListNode *deleteMiddle(ListNode *head) {
    int sz = len(head);
    // only one node
    if (sz == 1) {
      return nullptr;
    }
    int dbefore_idx = sz / 2 - 1;
    ListNode *cur = head;
    int i = 0;
    while (cur) {
      if (i == dbefore_idx) {
        break;
      }
      i++;
      cur = cur->next;
    }
    cur->next = cur->next->next;

    return head;
  }

private:
  int len(ListNode *head) {
    int ret = 0;

    while (head) {
      ret++;
      head = head->next;
    }

    return ret;
  }
};
