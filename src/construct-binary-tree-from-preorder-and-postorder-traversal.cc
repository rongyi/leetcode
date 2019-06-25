// http://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
#include "xxx.h"

class Solution {
public:
  // 前序和后序是不能唯一确定一颗树的，所以答案要求的是any
  TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
    const int n = pre.size();
    for (int i = 0; i < n; i++) {
      pos_idx_[post[i]] = i;
    }
    return recur(pre, post, 0, n - 1, 0, n - 1);
  }

private:
  TreeNode *recur(vector<int> &pre, vector<int> &post, int pre_start,
                  int pre_end, int post_start, int post_end) {
    if (pre_start > pre_end) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(pre[pre_start]);
    if (pre_start == pre_end) {
      return root;
    }
    int idx = pos_idx_[pre[pre_start + 1]];
    int offset = idx - post_start;
    root->left = recur(pre, post, pre_start + 1, pre_start + 1 + offset,
                       post_start, idx);
    root->right = recur(pre, post, pre_start + 1 + offset + 1, pre_end, idx + 1,
                        post_end);

    return root;
  }

private:
  unordered_map<int, int> pos_idx_;
};
