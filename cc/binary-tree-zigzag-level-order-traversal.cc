// http://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    dolevel(root, ret, 1, true);

    return ret;
  }

private:
  void dolevel(TreeNode *root, vector<vector<int>> &ret, int level,
               bool from_left) {
    if (!root) {
      return;
    }
    if (ret.size() < level) {
      ret.push_back({});
    }
    if (from_left) {
      ret[level - 1].push_back(root->val);
    } else {
      ret[level - 1].insert(ret[level - 1].begin(), root->val);
    }

    dolevel(root->left, ret, level + 1, !from_left);
    dolevel(root->right, ret, level + 1, !from_left);
  }
};
