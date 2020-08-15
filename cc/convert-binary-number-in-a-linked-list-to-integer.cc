// http://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/
#include "xxx.h"

class Solution {
public:
  int getDecimalValue(ListNode *head) {
    int ret = 0;

    while (head) {
      ret = ret * 2 + head->val;
      head = head->next;
    }

    return ret;
  }
};
