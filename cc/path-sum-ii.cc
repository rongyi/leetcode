// http://leetcode.com/problems/path-sum-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> ret;

    dfs(root, ret, {}, sum, 0);
    return ret;
  }

private:
  void dfs(TreeNode *root, vector<vector<int>> &ret, vector<int> cur,
           const int target, int acc) {
    if (!root) {
      return;
    }
    cur.push_back(root->val);
    acc += root->val;
    if (acc == target && root->left == nullptr && root->right == nullptr) {
      ret.push_back(cur);
    }
    dfs(root->left, ret, cur, target, acc);
    dfs(root->right, ret, cur, target, acc);
  }
};
