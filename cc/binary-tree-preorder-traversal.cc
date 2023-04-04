// http://leetcode.com/problems/binary-tree-preorder-traversal/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> ret;
    if (root) {
      s.push(root);
    }
    while (!s.empty()) {
      auto cur = s.top();
      s.pop();
      ret.push_back(cur->val);
      if (cur->right) {
        s.push(cur->right);
      }
      if (cur->left) {
        s.push(cur->left);
      }
    }

    return ret;
  }
};
