// http://leetcode.com/problems/longest-univalue-path/description/
#include "xxx.h"

class Solution {
public:
  int longestUnivaluePath(TreeNode *root) {
    if (!root) {
      return 0;
    }
    // node
    int ret = 0;
    recur(root, root->val, ret);
    // edges == node - 1;
    return ret - 1;
  }

private:
  //  表示从这个节点 val为target总共多长
  int recur(TreeNode *root, int target, int &max_count) {
    if (!root || root->val != target) {
      // before return we want to start brand new search from
      // here, if root is not null
      // side effect to calculate max_count
      if (root) {
        recur(root, root->val, max_count);
      }
      return 0;
    }
    // int ret = 1; // at least contain itself
    auto left = recur(root->left, target, max_count);
    auto right = recur(root->right, target, max_count);
    // ret += left + right;
    max_count = max(max_count, 1 + left + right);
    return max(left, right) + 1;
  }
};
