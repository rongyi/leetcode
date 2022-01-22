// http://leetcode.com/problems/rotate-list/description/
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
  ListNode *rotateRight(ListNode *head, int k) {
    const int n = len(head);
    if (n == 0) {
      return nullptr;
    }
    k %= n;
    if (k == 0) {
      return head;
    }

    auto p = head;
    int i = 0;
    while (p && i < n - k - 1) {
      p = p->next;
      i++;
    }
    //  |list | --> |list|
    //            ^
    //            |
    //    p      cut
    // we will split from here!
    auto newhead = p->next;
    // cut from here
    p->next = nullptr;
    // attach the bottom to head
    p = newhead;
    while (p->next) {
      p = p->next;
    }
    p->next = head;

    return newhead;
  }

private:
  int len(ListNode *head) {
    auto ret = 0;

    while (head) {
      ret++;
      head = head->next;
    }

    return ret;
  }
};

int main() {
  Solution so;
  ListNode l1(1), l2(2), l3(3);
  l1.next = &l2;
  l2.next = &l3;
  so.rotateRight(&l1, 1);
}
