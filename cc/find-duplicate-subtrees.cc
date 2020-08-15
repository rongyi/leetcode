// http://leetcode.com/problems/find-duplicate-subtrees/description/
#include "xxx.h"

class Solution {
public:
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    unordered_map<string, vector<TreeNode *>> cache;
    vector<TreeNode *> dups;
    tolist(root, cache);
    for (auto kv : cache) {
      if (kv.second.size() > 1) {
        // 随便哪个
        dups.push_back(kv.second[0]);
      }
    }
    return dups;
  }

private:
  string tolist(TreeNode *root,
                unordered_map<string, vector<TreeNode *>> &cache) {
    if (!root) {
      return "";
    }
    stringstream ss;
    ss << '(';
    ss << tolist(root->left, cache);
    ss << root->val;
    ss << tolist(root->right, cache);
    ss << ')';
    auto s = ss.str();
    cache[s].push_back(root);
    return s;
  }
};
