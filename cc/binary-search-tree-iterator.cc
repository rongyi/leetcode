// http://leetcode.com/problems/binary-search-tree-iterator/description/
#include "xxx.hpp"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    while (root) {
      stk_.push(root);
      root = root->left;
    }
  }

  int next() {
    auto *cur = stk_.top();
    stk_.pop();
    int val = cur->val;
    if (cur->right) {
      cur = cur->right;
      while (cur) {
        stk_.push(cur);
        cur = cur->left;
      }
    }

    return val;
  }

  bool hasNext() { return !stk_.empty(); }

private:
  stack<TreeNode *> stk_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
