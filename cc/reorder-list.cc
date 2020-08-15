// http://leetcode.com/problems/reorder-list/description/
#include "xxx.h"

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head) {
      return;
    }
    auto m = len(head);
    // cout << m << endl;
    ListNode dummy(-1);
    dummy.next = head;
    auto p = &dummy;
    for (int i = 0; i < m / 2; ++i) {
      p = p->next;
    }
    ListNode *first_half_tail = p;
    // hold the center node
    // 这里分奇偶数，奇数情况是把中间的一个节点放到最后，偶数则没有这种情况
    ListNode *odd_center = nullptr;
    ListNode *last_half = nullptr;
    if (m & 0x1) {
      odd_center = p->next;
      p = p->next;
    }
    last_half = p->next;
    // unchain
    first_half_tail->next = nullptr;
    if (odd_center) {
      odd_center->next = nullptr;
    }
    // reverse bottom half
    last_half = reverse(last_half);
    // now 比翼双飞
    auto *first_half = head;
    while (first_half && last_half) {
      // save
      auto fnext = first_half->next;
      auto lnext = last_half->next;

      first_half->next = last_half;

      // 需要在循环里面判断这种case，否则出去了就没法做了
      if (!last_half->next) {
        if (odd_center) {
          last_half->next = odd_center;
        }
      } else {
        last_half->next = fnext;
      }

      first_half = fnext;
      last_half = lnext;
    }
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
  // l4.next = &l5;
  so.reorderList(&l1);
  auto *p = &l1;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}
