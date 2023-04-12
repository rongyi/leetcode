// http://leetcode.com/problems/binary-tree-right-side-view/description/
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
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    if (!root) {
      return {};
    }
    queue<TreeNode *> q;
    q.push(root);
    // each layer's last node
    // TreeNode *last = root;
    vector<int> ret;
    while (!q.empty()) {
      ret.push_back(q.back()->val);
      int sz = q.size();
      for (int i = 0; i < sz; i++) {
        auto cur = q.front();
        q.pop();
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
    }

    return ret;
  }
};
