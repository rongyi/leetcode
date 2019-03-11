// http://leetcode.com/problems/find-bottom-left-tree-value/description/
#include "xxx.h"

class Solution {
public:
  // 层序遍历的最后一排的第一个元素
  int findBottomLeftValue(TreeNode *root) {
    vector<vector<int>> ret;
    levelOrder(root, ret, 1);

    auto lastrow = ret[ret.size() - 1];
    return lastrow[0];
  }

private:
  void levelOrder(TreeNode *root, vector<vector<int>> &ret, int level) {
    if (!root) {
      return;
    }
    if (level > ret.size()) {
      ret.push_back({});
    }
    ret.back().push_back(root->val);

    levelOrder(root->left, ret, level + 1);
    levelOrder(root->right, ret, level + 1);
  }
};
