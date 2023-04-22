// http://leetcode.com/problems/palindrome-linked-list/description/
#include "xxx.hpp"

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    vector<int> vals;
    ListNode *p = head;
    while (p) {
      vals.push_back(p->val);

      p = p->next;
    }

    for (int i = 0, j = vals.size() - 1; i < j; i++, j--) {
      if (vals[i] != vals[j]) {
        return false;
      }
    }

    return true;
  }
};
