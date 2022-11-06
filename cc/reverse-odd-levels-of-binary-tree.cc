// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *reverseOddLevels(TreeNode *root) {
    vector<vector<int>> ls;
    level_order(root, 1, ls);
    for (int i = 0; i < ls.size(); ++i) {
      if (i & 1) {
        reverse(ls[i].begin(), ls[i].end());
      }
    }
    vector<int> all;
    for (auto &l : ls) {
      for (auto val : l) {
        all.push_back(val);
      }
    }
    return mktree(all, 0);
  }

private:
  TreeNode *mktree(vector<int> &vals, int pos) {
    if (pos >= vals.size()) {
      return nullptr;
    }
    TreeNode *ret = new TreeNode(vals[pos]);
    ret->left = mktree(vals, pos * 2 + 1);
    ret->right = mktree(vals, pos * 2 + 2);

    return ret;
  }
  void level_order(TreeNode *cur, int height, vector<vector<int>> &ls) {
    if (!cur) {
      return;
    }
    if (ls.size() < height) {
      ls.push_back({});
    }
    ls[height - 1].push_back(cur->val);

    level_order(cur->left, height + 1, ls);
    level_order(cur->right, height + 1, ls);
  }
};
