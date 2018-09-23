// http://leetcode.com/problems/reverse-nodes-in-k-group/description/
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
  ListNode *reverseKGroup(ListNode *head, int k) {
    int l = len(head);
    if (k == 1) {
      return head;
    }
    if (k == l) {
      return reverse(head);
    }
    // int left = l - k;
    // this is not a full group, we don't touch this kind of group
    // only reverse full k group
    if (l < k) {
      return head;
    }

    auto p = head;
    int i = k;
    while (--i) {
      p = p->next;
    }
    auto nexround = p->next;
    // cut here
    p->next = nullptr;
    auto rvred_group = reverse(head);
    auto end = rvred_group;

    while (end->next) {
      end = end->next;
    }
    end->next = reverseKGroup(nexround, k);

    return rvred_group;
  }

private:
  int len(ListNode *head) {
    int ret = 0;
    while (head) {
      ++ret;
      head = head->next;
    }
    return ret;
  }
  ListNode *reverse(ListNode *head) {
    ListNode dummy(-1);
    while (head) {
      auto nexround = head->next;
      // insert at header
      auto p = dummy.next;
      dummy.next = head;
      head->next = p;

      head = nexround;
    }

    return dummy.next;
  }
};
int main() {
  Solution so;
  ListNode l1(1), l2(2), l3(3), l4(4), l5(5);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;
  // auto ret = so.reverse(&l1);
  // cout << ret->val << endl;
  auto ret = so.reverseKGroup(&l1, 2);
  while (ret) {
    cout << ret->val << " ";
    ret = ret->next;
  }
  cout << endl;
}
