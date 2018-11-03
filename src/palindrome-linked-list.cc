// http://leetcode.com/problems/palindrome-linked-list/description/
#include "simpleone.h"

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (!head) {
      return true;
    }
    int n = len(head);
    auto *p = head;
    for (int i = 0; i < n / 2; i++) {
      head = head->next;
    }
    // 这里没有必要断开，而是指望后面的判断， r和p同时不空
    ListNode *bottom_half = head;
    // odd
    if (n & 1) {
      bottom_half = bottom_half->next;
    }
    auto *r = reverse(bottom_half);
    while (r && p) {
      if (r->val != p->val) {
        return false;
      }
      r = r->next;
      p = p->next;
    }
    return true;

  }

private:
  ListNode *reverse(ListNode *head) {
    ListNode dummy(-1);
    ListNode *cur = &dummy;
    while (head) {
      // backup
      auto *next = head->next;
      head->next = cur->next;
      cur->next = head;

      head = next;
    }
    return dummy.next;
  }
  int len(ListNode *head) {
    int ret = 0;
    while (head) {
      ret++;
      head = head->next;
    }
    return ret;
  }
};

int main() {
  Solution so;
  ListNode l1(1), l2(2);
  l1.next = &l2;
  auto ret = so.isPalindrome(&l1);
  cout << ret << endl;
}
