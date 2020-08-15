// http://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    if (!root) {
      return true;
    }
    queue<TreeNode *> q;
    q.push(root);
    bool prev_hole = false;
    while (!q.empty()) {

      // 一层一层来
      int cur_level_len = q.size();
      bool has_hole = false;
      for (int i = 0; i < cur_level_len; i++) {
        auto cur = q.front();
        q.pop();
        if (cur == nullptr) {
          if (!has_hole) {
            has_hole = true;
          }
          continue;
        }
        // 遇到一个节点前面有空洞，立即返回
        // 或者前一行有hole，然后现在到这一行发现有飞空节点了，赶紧撤
        if (has_hole || prev_hole) {
          return false;
        }

        if (cur->left) {
          q.push(cur->left);
        } else {
          q.push(nullptr);
        }
        if (cur->right) {
          q.push(cur->right);
        } else {
          q.push(nullptr);
        }
      }

      prev_hole = has_hole;
    }
    return true;
  }
};
