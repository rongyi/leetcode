// http://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> largestValues(TreeNode *root) {
    if (!root) {
      return {};
    }
    vector<vector<int>> levels;
    levelOrder(root, levels, 1);
    vector<int> ret;

    for (auto l : levels) {
      ret.push_back(*max_element(l.begin(), l.end()));
    }

    return ret;
  }

private:
  void levelOrder(TreeNode *root, vector<vector<int>> &ret, int level) {
    if (!root) {
      return;
    }

    if (ret.size() < level) {
      ret.push_back({});
    }
    ret[level - 1].push_back(root->val);

    levelOrder(root->left, ret, level + 1);
    levelOrder(root->right, ret, level + 1);
  }
};
