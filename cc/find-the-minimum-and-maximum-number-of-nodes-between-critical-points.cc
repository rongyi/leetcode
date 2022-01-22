// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
#include "xxx.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    vector<int> critical_indexs;
    ;
    int prev = head->val;
    ListNode *cur = head->next;
    int cur_index = 1;
    while (cur->next) {
      // local maxima?
      bool is_maxima = false;
      bool is_minima = false;
      if (cur->val > prev && cur->val > cur->next->val) {
        is_maxima = true;
      }
      // local minima?
      if (cur->val < prev && cur->val < cur->next->val) {
        is_minima = true;
      }
      if (is_maxima || is_minima) {
        critical_indexs.push_back(cur_index);
      }

      // rolling step
      cur_index++;
      prev = cur->val;
      cur = cur->next;
    }
    if (critical_indexs.size() < 2) {
      return {-1, -1};
    }
    int min_diff = numeric_limits<int>::max();
    for (int i = 0; i < critical_indexs.size() - 1; ++i) {
      min_diff = min(min_diff, critical_indexs[i + 1] - critical_indexs[i]);
    }
    return {min_diff, critical_indexs.back() - critical_indexs.front()};
  }
};
