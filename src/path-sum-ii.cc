// http://leetcode.com/problems/path-sum-ii/description/
#include "one.h"

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> ret;
    if (!root) {
      return ret;
    }
    vector<int> cur;
    dfs(root, ret, cur, sum);

    return ret;
  }
private:
  void dfs(TreeNode *root, vector<vector<int>> &ret, vector<int> cur,
           const int target) {
    if (!root) {
      return;
    }
    if (!root->left && !root->right) {
      // don't forget the last leaf node!
      cur.push_back(root->val);
      auto cur_sum = accumulate(cur.begin(), cur.end(), 0);
      if (cur_sum == target) {
        ret.push_back(cur);
      }
      return;
    }
    cur.push_back(root->val);
    dfs(root->left, ret, cur, target);
    dfs(root->right, ret, cur, target);
  }
};
