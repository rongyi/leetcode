// http://leetcode.com/problems/recover-binary-search-tree/description/
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
  void recoverTree(TreeNode *root) {
    vector<TreeNode *> ps;
    vector<int> vs;

    inorder(root, ps, vs);
    sort(vs.begin(), vs.end());

    for (int i = 0; i < ps.size(); ++i) {
      ps[i]->val = vs[i];
    }
  }

private:
  void inorder(TreeNode *root, vector<TreeNode *> &ps, vector<int> &vs) {
    if (!root) {
      return;
    }
    inorder(root->left, ps, vs);

    ps.push_back(root);
    vs.push_back(root->val);

    inorder(root->right, ps, vs);
  }
};
