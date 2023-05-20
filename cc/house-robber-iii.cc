// http://leetcode.com/problems/house-robber-iii/description/
#include "xxx.hpp"

class Solution {
public:
  int rob(TreeNode *root) {
    int hunt_cur = 0;
    int keep_cur = 0;

    dorob(root, &hunt_cur, &keep_cur);

    return max(hunt_cur, keep_cur);
  }

private:
  void dorob(TreeNode *root, int *hunt_cur, int *keep_cur) {
    if (!root) {
      return;
    }
    int hunt_left = 0;
    int keep_left = 0;
    int hunt_right = 0;
    int keep_right = 0;

    dorob(root->left, &hunt_left, &keep_left);
    dorob(root->right, &hunt_right, &keep_right);

    // if i rob cur, then child can not be touched
    *hunt_cur = root->val + keep_left + keep_right;
    // 当前节点不抢，那么对于子节点来讲就有很大的自由度，
    // 可抢也可以不抢，所以选取两边各自的最大值，
    // 抢不抢两边是各自独立的
    *keep_cur = max(hunt_left, keep_left) + max(hunt_right, keep_right);
  }
};
