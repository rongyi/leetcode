// http://leetcode.com/problems/even-odd-tree/description/
#include "xxx.h"

class Solution {
public:
  bool isEvenOddTree(TreeNode *root) {
    vector<vector<int>> ls;
    return level_order(root, ls, 1);
  }

private:
  bool level_order(TreeNode *cur, vector<vector<int>> &level, int cur_level) {
    if (!cur) {
      return true;
    }

    if (cur_level > level.size()) {
      level.push_back({});
    }
    // 检测奇偶性要求, lazy返回
    if (cur_level & 1) {
      // 要求这一层遇到的都是奇数
      if ((cur->val & 1) == 0) {
        return false;
      }
      if (level[cur_level - 1].size() > 0 &&
          cur->val <= level[cur_level - 1].back()) {
        return false;
      }
    } else {
      // 要求这一层遇到的都是偶数
      if ((cur->val & 1) == 1) {
        return false;
      }
      if (level[cur_level - 1].size() > 0 &&
          cur->val >= level[cur_level - 1].back()) {
        return false;
      }
    }

    level[cur_level - 1].push_back(cur->val);

    // 这里是与不能是lazy的 ||
    return level_order(cur->left, level, cur_level + 1) &&
           level_order(cur->right, level, cur_level + 1);
  }
};
