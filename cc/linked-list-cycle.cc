// http://leetcode.com/problems/linked-list-cycle/description/
#include "xxx.hpp"

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head)
      return false;
    if (!head->next || !head->next->next)
      return false;
    ListNode *slow = head;
    ListNode *fast = head;
    while (slow && fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};
