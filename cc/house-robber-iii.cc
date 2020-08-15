// http://leetcode.com/problems/house-robber-iii/description/
#include "xxx.h"

class Solution {
public:
  int rob(TreeNode *root) {
    int hunt_cur = 0;
    int leave_cur = 0;

    dorob(root, &hunt_cur, &leave_cur);

    return max(hunt_cur, leave_cur);
  }

private:
  void dorob(TreeNode *root, int *hunt_cur, int *leave_cur) {
    if (!root) {
      return;
    }
    int hunt_left = 0;
    int leave_left = 0;
    int hunt_right = 0;
    int leave_right = 0;
    dorob(root->left, &hunt_left, &leave_left);
    dorob(root->right, &hunt_right, &leave_right);

    *hunt_cur = root->val + leave_left + leave_right;
    // 当前节点不抢，那么对于子节点来讲就有很大的自由度，可抢也可以不抢，所以选取两边各自的最大值，
    // 抢不抢两边是各自独立的
    *leave_cur = max(hunt_left, leave_left) + max(hunt_right, leave_right);
  }
};
