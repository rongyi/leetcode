// http://leetcode.com/problems/next-greater-node-in-linked-list/description/
#include "xxx.h"

class Solution {
public:
  vector<int> nextLargerNodes(ListNode *head) {
    vector<int> lst;
    while (head) {
      lst.push_back(head->val);
      head = head->next;
    }
    stack<int> stk;
    vector<int> ret(lst.size(), 0);
    for (int i = lst.size() - 1; i >= 0; i--) {
      auto cur = lst[i];
      // 小的全滚蛋，这样栈顶就是第一个比他大的元素
      while (!stk.empty() && stk.top() <= cur) {
        stk.pop();
      }
      ret[i] = stk.empty() ? 0 : stk.top();
      stk.push(cur);
    }

    return ret;
  }
};
