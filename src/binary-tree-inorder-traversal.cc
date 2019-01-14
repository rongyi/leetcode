// http://leetcode.com/problems/leetcode/binary-tree-inorder-traversal/description/
#include "xxx.h"

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
  vector<int> inorderTraversalRecursive(TreeNode *root) {
    vector<int> ret;
    action(root, ret);
    return ret;
  }
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> stk;
    TreeNode *p = root;
    vector<int> ret;
    while (!stk.empty() || p != nullptr) {
      if (p != nullptr) {
        stk.push(p);
        p = p->left;
      } else {
        p = stk.top();
        stk.pop();
        ret.push_back(p->val);
        p = p->right;
      }
    }
    return ret;
  }

private:
  void action(TreeNode *root, vector<int> &ret) {
    if (!root) {
      return;
    }

    action(root->left, ret);
    ret.push_back(root->val);
    action(root->right, ret);
  }
};
