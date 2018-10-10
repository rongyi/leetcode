// http://leetcode.com/problems/leetcode/binary-tree-level-order-traversal-ii/description/
#include "one.h"

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
    if (!root) {
      return ret;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> cur;
      int cur_cnt = q.size();
      for (int i = 0; i < cur_cnt; ++i) {
        cur.push_back(q.front()->val);
        if (q.front()->left) {
          q.push(q.front()->left);
        }
        if (q.front()->right) {
          q.push(q.front()->right);
        }
        q.pop();
      }
      ret.insert(ret.begin(), cur);
    }
    return ret;
  }
};
