// http://leetcode.com/problems/merge-in-between-linked-lists/description/
#include "xxx.hpp"

class Solution {
public:
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    // they promise list2 is not nil
    ListNode *second_head = list2;
    ListNode *second_tail = list2;
    // second tail stop at the end of list2
    while (second_tail->next) {
      second_tail = second_tail->next;
    }

    // find the node before of index (a - 1)
    ListNode *before_indexa = list1;
    int i = 0;
    // a >= 1, so a is not head
    // 停留在之前
    while (i < a - 1 && before_indexa) {
      before_indexa = before_indexa->next;
      i++;
    }

    // don't cut yet, we need to find node of index (b)
    ListNode *tail = before_indexa;
    i = a - 1;

    // 停留在b上
    while (i < b && tail) {
      tail = tail->next;
      i++;
    }
    // 开始手术
    before_indexa->next = second_head;
    second_tail->next = tail->next;
    tail->next = nullptr;

    return list1;
  }
};
