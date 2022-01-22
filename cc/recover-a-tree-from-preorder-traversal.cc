// http://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/
#include "xxx.hpp"

class Solution {
public:
  TreeNode *recoverFromPreorder(string s) {
    stack<TreeNode *> stk;
    const int n = s.size();

    for (int i = 0; i < n;) {
      int level = 0;
      while (s[i] == '-') {
        ++level;
        i++;
      }
      int digits = 0;
      while (i + digits < n && s[i + digits] != '-') {
        ++digits;
      }
      TreeNode *new_node = new TreeNode(stoi(s.substr(i, digits)));

      while (stk.size() > level) {
        stk.pop();
      }

      if (!stk.empty()) {
        if (stk.top()->left) {
          stk.top()->right = new_node;
        } else {
          stk.top()->left = new_node;
        }
      }
      stk.push(new_node);

      i += digits;
    }

    while (stk.size() > 1) {
      stk.pop();
    }
    // the root node
    return stk.top();
  }
};
