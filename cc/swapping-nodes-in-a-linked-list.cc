// http://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
#include "xxx.h"

class Solution {
public:
  ListNode *swapNodes(ListNode *head, int k) {
    auto n = len(head);
    ListNode *l = head;
    ListNode *r = head;

    for (int i = 0; i < n - k && r; i++) {
      // 注意停止循环是l已经落在了下一个上，正好是想要的那个k位置
      r = r->next;
    }

    for (int i = 0; i < k - 1 && l; i++) {
      l = l->next;
    }
    if (l != r) {
      swap(l->val, r->val);
    }

    return head;
  }

private:
  int len(ListNode *head) {
    int len = 0;
    while (head) {
      head = head->next;
      len++;
    }

    return len;
  }
};
