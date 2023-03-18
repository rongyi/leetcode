// http://leetcode.com/problems/leetcode/binary-tree-level-order-traversal-ii/description/
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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> ret;

    recur(root, ret, 1);
    reverse(ret.begin(), ret.end());

    return ret;
  }

private:
  void recur(TreeNode *cur, vector<vector<int>> &ret, int level) {
    if (!cur) {
      return;
    }
    if (ret.size() < level) {
      ret.push_back({});
    }
    ret[level - 1].push_back(cur->val);
    recur(cur->left, ret, level + 1);
    recur(cur->right, ret, level + 1);
  }
};
