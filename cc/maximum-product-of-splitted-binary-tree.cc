// http://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
#include "xxx.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
  int maxProduct(TreeNode *root) {
    const int mod = pow(10, 9) + 7;
    long long t = dfs(root);
    long long ret = 0;
    for (auto n : sums_) {
      ret = max(ret, (t - n) * n);
    }
    return ret % mod;
  }

private:
  int dfs(TreeNode *node) {
    if (!node) {
      return 0;
    }
    return *sums_.insert(dfs(node->left) + dfs(node->right) + node->val).first;
  }

private:
  unordered_set<int> sums_;
};
