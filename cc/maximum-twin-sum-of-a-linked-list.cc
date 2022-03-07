// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
#include "xxx.hpp"

class Solution {
public:
  int pairSum(ListNode *head) {
    vector<int> vals;
    while (head) {
      vals.push_back(head->val);
      head = head->next;
    }

    int sz = vals.size();
    int ret = 0;

    for (int i = 0; i < sz / 2; ++i) {
      auto cur_sum = vals[i] + vals[sz - i - 1];
      ret = max(ret, cur_sum);
    }

    return ret;
  }
};
