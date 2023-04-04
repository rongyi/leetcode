// http://leetcode.com/problems/binary-tree-postorder-traversal/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    vector<int> ret;
    if (root) {
      s1.push(root);
    }

    while (!s1.empty()) {
      auto cur = s1.top();
      s1.pop();
      s2.push(cur);
      if (cur->left) {
        s1.push(cur->left);
      }
      if (cur->right) {
        s1.push(cur->right);
      }
    }

    while (!s2.empty()) {
      ret.push_back(s2.top()->val);
      s2.pop();
    }

    return ret;
  }
};
