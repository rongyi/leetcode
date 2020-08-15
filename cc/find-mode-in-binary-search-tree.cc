// http://leetcode.com/problems/find-mode-in-binary-search-tree/description/
#include "xxx.h"

class Solution {
public:
  vector<int> findMode(TreeNode *root) {
    if (!root) {
      return {};
    }
    unordered_map<int, int> count;
    int count_max = 0;
    traverse(root, count, count_max);

    vector<int> ret;
    for (auto kv : count) {
      if (kv.second == count_max) {
        ret.push_back(kv.first);
      }
    }
    return ret;
  }
  void traverse(TreeNode *node, unordered_map<int, int> &count,
                int &count_max) {
    if (!node) {
      return;
    }

    count[node->val]++;
    count_max = max(count_max, count[node->val]);

    traverse(node->left, count, count_max);
    traverse(node->right, count, count_max);
  }
};
