// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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
  int getMinimumDifference(TreeNode *root) {
    vector<int> lst;
    inorder(root, lst);
    int ret = numeric_limits<int>::max();
    for (int i = 1; i < lst.size(); ++i) {
      ret = min(ret, lst[i] - lst[i - 1]);
    }
    return ret;
  }

private:
  void inorder(TreeNode *root, vector<int> &lst) {
    if (!root) {
      return;
    }
    inorder(root->left, lst);
    lst.push_back(root->val);
    inorder(root->right, lst);
  }
};
