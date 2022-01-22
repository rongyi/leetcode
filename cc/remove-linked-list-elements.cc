// http://leetcode.com/problems/remove-linked-list-elements/description/
#include "xxx.hpp"

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    if (!head) {
      return nullptr;
    }

    ListNode dummy(-1);
    dummy.next = head;
    ListNode *cur = &dummy;
    while (cur->next && cur->next->val != val) {
      cur = cur->next;
    }
    // now cur->next is the target to delete
    ListNode *target = cur->next;
    // the target maybe nullptr
    if (target) {
      cur->next = target->next;
      target->next = nullptr;
    }

    // recursive the problem
    cur->next = removeElements(cur->next, val);

    // delete(target);
    return dummy.next;
  }
};

int main() {
  Solution so;
  ListNode l1(1), l2(1);
  l1.next = &l2;
  auto head = so.removeElements(&l1, 1);
  if (!head) {
    cout << "right" << endl;
  }
}
