// http://leetcode.com/problems/binary-tree-paths/description/
#include "xxx.h"

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<vector<int>> ls;
    vector<int> cur;
    dfs(root, ls, cur);
    vector<string> ret;
    for (auto &l : ls) {
      // cout << l.size() << endl;
      ret.push_back(mapvector(l));
    }
    return ret;
  }

private:
  string mapvector(vector<int> &lst) {
    if (lst.empty()) {
      return "";
    }
    stringstream ss;
    for (int i = 0; i < lst.size(); i++) {
      ss << lst[i];
      if (i != lst.size() - 1) {
        ss << "->";
      }
    }
    return ss.str();
  }
  void dfs(TreeNode *root, vector<vector<int>> &ret, vector<int> cur) {
    if (!root) {
      return;
    }
    cur.push_back(root->val);
    if (!root->left && !root->right) {
      ret.push_back(cur);
      return;
    }
    dfs(root->left, ret, cur);
    dfs(root->right, ret, cur);
  }
};
