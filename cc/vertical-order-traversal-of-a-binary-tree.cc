// http://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<int, map<int, set<int>>> cache;
    vector<vector<int>> ret;

    recur(root, 0, 0, cache);

    for (auto kv : cache) {
      ret.push_back({});
      for (auto kv2 : kv.second) {
        ret.back().insert(end(ret.back()), begin(kv2.second), end(kv2.second));
      }
    }
    return ret;
  }
  void recur(TreeNode *root, int x, int y,
             map<int, map<int, set<int>>> &cache) {
    if (!root) {
      return;
    }
    cache[x][y].insert(root->val);
    recur(root->left, x - 1, y + 1, cache);
    recur(root->right, x + 1, y + 1, cache);
  }
};
