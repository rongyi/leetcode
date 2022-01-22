// http://leetcode.com/problems/split-linked-list-in-parts/description/
#include "xxx.hpp"

class Solution {
public:
  vector<ListNode *> splitListToParts(ListNode *root, int k) {
    // calculate linkedlist size
    int len = 0;
    ListNode *p = root;
    while (p) {
      len++;
      p = p->next;
    }
    int avg = len / k;
    int left = len % k;
    // 分配的数组
    vector<int> alloc(k, avg);
    for (int i = 0; i < left; i++) {
      alloc[i] += 1;
    }
    // 根据alloc来切linkedlist
    vector<ListNode *> ret(k, nullptr);
    p = root;

    for (int i = 0; i < k; i++) {
      int cut_pos = alloc[i];
      if (cut_pos == 0) {
        // nullptr already set
        continue;
      }
      ret[i] = p;

      int cnt = 0;
      // 要停在断开的节点之上，不能是后面,因为是单链表
      while (cnt < cut_pos - 1) {
        p = p->next;
        cnt++;
      }
      // 从这里断开
      ListNode *tmp = p->next;
      p->next = nullptr;
      p = tmp;
    }

    return ret;
  }
};

int main() {
  Solution so;
  ListNode n1(1), n2(2), n3(3), n4(4);
  n1.next = &n2, n2.next = &n3, n3.next = &n4;
  so.splitListToParts(&n1, 5);
}
