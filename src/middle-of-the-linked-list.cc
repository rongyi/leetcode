// https://leetcode.com/problems/middle-of-the-linked-list/description/
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
  ListNode *middleNode(ListNode *head) {
    auto cp = head;
    auto l = len(cp);
    auto mid = l / 2;
    int i = 0;
    auto ret = head;
    while (i < mid) {
      ret = ret->next;
      ++i;
    }
    return ret;
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
};

int main() {
  Solution so;
  ListNode l1(1), l2(2), l3(3);
  l1.next = &l2;
  l2.next = &l3;
  auto ret = so.middleNode(&l1);
  cout << ret->val << endl;
}
