// https://leetcode.com/problems/linked-list-components/description/
#include "one.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  int numComponents(ListNode *head, vector<int> &G) {
    unordered_set<int> subset;
    for (auto cur : G) {
      subset.insert(cur);
    }
    int ret = 0;
    auto p = head;
    auto in_group = false;
    // 总体策略就是边沿触发,遇到不在一个group里就添加前面的group
    // 但是最后一个没有机会触发，所以要么塞个元素触发，要么自己判断一下，
    // 这里自己判断一下

    while (p) {
      // we enter in a group;
      if (subset.find(p->val) != subset.end()) {
        if (!in_group) {
          in_group = true;
        }

        // this is the last node
        if (p->next == nullptr && in_group) {
          ++ret;
        }
      } else { // not in this group
        // we are leaving a group
        if (in_group) {
          in_group = false;
          ++ret; // plus the prev group
        }
      }
      p = p->next;
    }

    return ret;
  }
};
