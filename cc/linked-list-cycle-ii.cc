// http://leetcode.com/problems/leetcode/linked-list-cycle-ii/description/
#include "xxx.hpp"

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    auto *slow = head;
    auto *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        auto *slow2 = head;
        while (slow2 != slow) {
          slow2 = slow2->next;
          slow = slow->next;
        }
        return slow2;
      }
    }

    return nullptr;
  }
};
