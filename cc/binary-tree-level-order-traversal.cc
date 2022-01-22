// http://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ret;

    dolevel(root, ret, 1);

    return ret;
  }

private:
  void dolevel(TreeNode *root, vector<vector<int>> &ret, int level) {
    if (!root) {
      return;
    }

    if (ret.size() < level) {
      ret.push_back({});
    }

    ret[level - 1].push_back(root->val);
    dolevel(root->left, ret, level + 1);
    dolevel(root->right, ret, level + 1);
  }
};
