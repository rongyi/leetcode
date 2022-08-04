// https://leetcode.com/problems/spiral-matrix-iv/
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
  vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    vector<vector<int>> ret(m, vector<int>(n, -1));
    // direction
    // 0 right
    // 1 down
    // 2 left
    // 3 up
    int cur_direction = 0;

    int right_end = n;
    int down_end = m;
    int left_end = -1;
    int up_end = 0; // up end will not cross the first row

    while (head) {
      if (cur_direction == 0) {
        for (int j = left_end + 1; j < right_end && head; j++) {
          ret[up_end][j] = head->val;
          head = head->next;
        }

        cur_direction = 1;
        right_end--;
        // cout << "right" << endl;
      } else if (cur_direction == 1) {
        for (int i = up_end + 1; i < down_end && head; i++) {
          // already minus 1
          ret[i][right_end] = head->val;

          head = head->next;
        }

        // make i at last pos
        cur_direction = 2;
        down_end--;
      } else if (cur_direction == 2) {
        for (int j = right_end - 1; j > left_end && head; j--) {
          ret[down_end][j] = head->val;
          head = head->next;
        }
        // make j at last pos
        cur_direction = 3;
        left_end++;
      } else if (cur_direction == 3) {
        for (int i = down_end - 1; i > up_end && head; --i) {
          ret[i][left_end] = head->val;
          head = head->next;
        }

        cur_direction = 0;
        up_end++;
      }
    }
    return ret;
  }
};
