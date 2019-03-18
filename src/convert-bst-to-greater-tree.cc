// http://leetcode.com/problems/convert-bst-to-greater-tree/description/
#include "xxx.h"

class Solution {
public:
  TreeNode *convertBST(TreeNode *root) {
    vector<int> ret;
    unordered_map<int, int> index;
    inorder(root, ret);
    for (int i = 0; i < ret.size(); i++) {
      index[ret[i]] = i;
    }

    vector<int> postfix_sum(ret.size(), 0);
    int prev = 0;
    for (int i = ret.size() - 1; i >= 0; --i) {
      postfix_sum[i] = ret[i] + prev;
      prev = postfix_sum[i];
    }

    update(root, postfix_sum, index);

    return root;
  }

private:
  void inorder(TreeNode *root, vector<int> &ret) {
    if (!root) {
      return;
    }

    inorder(root->left, ret);
    ret.push_back(root->val);
    inorder(root->right, ret);
  }

  void update(TreeNode *root, vector<int> &sum,
              unordered_map<int, int> &index) {
    if (!root) {
      return;
    }

    update(root->left, sum, index);
    root->val = sum[index[root->val]];
    update(root->right, sum, index);
  }
};
