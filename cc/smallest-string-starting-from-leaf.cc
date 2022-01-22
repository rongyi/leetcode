// http://leetcode.com/problems/smallest-string-starting-from-leaf/description/
#include "xxx.hpp"

class Solution {
public:
  string smallestFromLeaf(TreeNode *root) {
    vector<string> paths;
    string cur{};
    dfs(root, cur, paths);
    sort(paths.begin(), paths.end());

    return paths[0];
  }
  void dfs(TreeNode *root, string cur, vector<string> &paths) {
    if (!root) {
      return;
    }

    cur.push_back('a' + root->val);
    if (!root->left && !root->right) {
      reverse(cur.begin(), cur.end());
      paths.push_back(cur);
      return;
    }

    dfs(root->left, cur, paths);
    dfs(root->right, cur, paths);
  }
};
