// http://leetcode.com/problems/deepest-leaves-sum/description/
#include "xxx.hpp"

class Solution {
public:
  int deepestLeavesSum(TreeNode *root) {
    vector<vector<int>> levels;
    lorder(root, levels, 1);

    auto &last = levels[levels.size() - 1];
    int ret = accumulate(last.begin(), last.end(), 0);

    return ret;
  }

private:
  void lorder(TreeNode *cur, vector<vector<int>> &levels, int cur_level) {
    if (!cur) {
      return;
    }
    if (cur_level > levels.size()) {
      levels.push_back({});
    }
    levels[cur_level - 1].push_back(cur->val);

    lorder(cur->left, levels, cur_level + 1);
    lorder(cur->right, levels, cur_level + 1);
  }
};
