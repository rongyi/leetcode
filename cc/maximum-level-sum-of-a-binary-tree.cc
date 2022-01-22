// http://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
#include "xxx.hpp"

class Solution {
public:
  int maxLevelSum(TreeNode *root) {
    vector<vector<int64_t>> levels;
    leveOrder(root, 1, levels);
    vector<int64_t> acc(levels.size(), 0);
    int ret = 0;
    int64_t max_value = numeric_limits<int64_t>::min();
    for (int i = 0; i < levels.size(); ++i) {
      int64_t init = 0;
      acc[i] = accumulate(levels[i].begin(), levels[i].end(), init);

      if (acc[i] > max_value) {
        max_value = acc[i];
        ret = i;
      }
    }
    return ret + 1;
  }

private:
  void leveOrder(TreeNode *root, int level, vector<vector<int64_t>> &ls) {
    if (!root) {
      return;
    }
    if (ls.size() < level) {
      ls.push_back({});
    }
    ls[level - 1].push_back(root->val);
    leveOrder(root->left, level + 1, ls);
    leveOrder(root->right, level + 1, ls);
  }
};
