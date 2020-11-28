// http://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
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
  int countPairs(TreeNode *root, int distance) {
    count_ = 0;
    dfs(root, distance);

    return count_;
  }

private:
  vector<int> dfs(TreeNode *root, int distance) {
    if (!root) {
      return {};
    }
    auto left = dfs(root->left, distance);
    auto right = dfs(root->right, distance);
    // a leaf node!
    if (left.size() == 0 && right.size() == 0) {
      return {1};
    }
    vector<int> ret;
    for (auto l1 : left) {
      for (auto l2 : right) {
        if ((l1 + l2) <= distance) {
          count_++;
        }
      }
    }
    // merge as one
    for (auto l : left) {
      ret.push_back(l + 1);
    }
    for (auto r : right) {
      ret.push_back(r + 1);
    }

    return ret;
  }

private:
  int count_;
};
