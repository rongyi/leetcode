// https://leetcode.com/problems/remove-nodes-from-linked-list/
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
  ListNode *removeNodes(ListNode *head) {
    vector<int> mono;
    ListNode *p = head;
    while (p != nullptr) {
      int cur = p->val;
      while (!mono.empty() && mono.back() < cur) {
        mono.pop_back();
      }
      mono.push_back(cur);
      p = p->next;
    }
    ListNode ret(-1);
    ListNode *tail = &ret;
    int i = 0;
    p = head;
    while (p != nullptr) {
      if (p->val == mono[i]) {
        tail->next = p;
        tail = tail->next;
        i++;
      }
      p = p->next;
    }

    return ret.next;
  }
};
