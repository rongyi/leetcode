// http://leetcode.com/problems/leetcode/binary-tree-inorder-traversal/description/
#include "xxx.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    inorderTraversal(root, ret);
    return ret;
  }

private:
  void inorderTraversal(TreeNode *root, vector<int> &ret) {
    stack<TreeNode *> stk;

    TreeNode *cur = root;

    while (cur != nullptr || !stk.empty()) {
      if (cur) {
        stk.push(cur);
        cur = cur->left;
      } else {
        cur = stk.top();
        stk.pop();
        ret.push_back(cur->val);
        cur = cur->right;
      }
    }
  }
};
