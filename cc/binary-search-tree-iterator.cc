// http://leetcode.com/problems/binary-search-tree-iterator/description/
#include "xxx.hpp"

class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    while (root) {
      s_.push(root);
      root = root->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !s_.empty();
  }

  /** @return the next smallest number */
  int next() {
    TreeNode *cur = s_.top();
    s_.pop();
    TreeNode *ret = cur;
    if (cur->right) {
      cur = cur->right;
      while (cur) {
        s_.push(cur);
        cur = cur->left;
      }
    }
    return ret->val;
  }
private:
  stack<TreeNode *> s_;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
