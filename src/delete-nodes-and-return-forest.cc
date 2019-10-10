// http://leetcode.com/problems/delete-nodes-and-return-forest/description/
#include "xxx.h"

class Solution {
public:
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    unordered_set<int> uniq(to_delete.begin(), to_delete.end());
    vector<TreeNode *> ret;

    doDel(root, ret, uniq, true);

    return ret;
  }

private:
  TreeNode *doDel(TreeNode *root, vector<TreeNode *> &ret,
                  unordered_set<int> &targets, bool is_root) {
    if (!root) {
      return nullptr;
    }

    bool should_delete = targets.find(root->val) != targets.end();

    if (is_root && !should_delete) {
      ret.push_back(root);
    }

    root->left = doDel(root->left, ret, targets, should_delete);
    root->right = doDel(root->right, ret, targets, should_delete);

    return should_delete ? nullptr : root;
  }
};
