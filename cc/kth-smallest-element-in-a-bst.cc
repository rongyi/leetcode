// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
#include "xxx.hpp"

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> stk;
    TreeNode *p = root;
    while (p) {
      stk.push(p);
      p = p->left;
    }
    while (!stk.empty()) {
      auto *cur = stk.top();
      stk.pop();
      k--;
      if (k == 0) {
        return cur->val;
      }
      // right child
      cur = cur->right;
      while (cur) {
        stk.push(cur);
        // to the left again
        cur = cur->left;
      }
    }
    // make compiler happy
    return -1;
  }
};
