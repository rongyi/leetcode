// http://leetcode.com/problems/binary-tree-paths/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> output;
    recur(root, "", output);

    return output;
  }

private:
  void recur(TreeNode *cur, string path, vector<string> &ret) {
    if (!cur) {
      return;
    }
    path += to_string(cur->val);
    if (!cur->left && !cur->right) {
      ret.push_back(path);
      return;
    }

    path += "->";
    recur(cur->left, path, ret);
    recur(cur->right, path, ret);
  }
};
