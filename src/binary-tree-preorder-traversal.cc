// http://leetcode.com/problems/binary-tree-preorder-traversal/description/
#include "xxx.h"

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ret;
    if (!root) {
      return ret;
    }
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty()) {
      auto p = stk.top();
      stk.pop();
      ret.push_back(p->val);

      if (p->right) {
        stk.push(p->right);
      }
      if (p->left) {
        stk.push(p->left);
      }
    }

    return ret;
  }
};
