// https://leetcode.com/problems/merge-bsts-to-create-single-bst/
#include "xxx.hpp"
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
  // each tree have at most 3 nodes, this restriction
  // make this problem much easier
  TreeNode *canMerge(vector<TreeNode *> &trees) {
    // remeber headers by its value
    unordered_map<int, TreeNode *> headers;
    // count node
    unordered_map<int, int> value_count;
    for (auto t : trees) {
      headers[t->val] = t;
      ++value_count[t->val];
      // also child count
      if (t->left) {
        ++value_count[t->left->val];
      }
      if (t->right) {
        ++value_count[t->right->val];
      }
    }
    // after we finish count, only header have only 1 count
    // that is what we looking for as the king node
    for (auto t : trees) {
      // construct from here
      if (value_count[t->val] == 1) {
        if (canBuild(t, headers, numeric_limits<int>::min(),
                     numeric_limits<int>::max())) {
          if (headers.size() == 1) {
            return t;
          }
        }
      }
    }
    return nullptr;
  }

private:
  bool canBuild(TreeNode *cur, unordered_map<int, TreeNode *> &headers,
                int left_limit, int right_limit) {
    if (cur == nullptr) {
      return true;
    }
    // bound check
    if (cur->val <= left_limit || cur->val >= right_limit) {
      return false;
    }
    if (cur->left == nullptr && cur->right == nullptr) {
      auto it = headers.find(cur->val);
      // also note the newly find node must not be itself
      if (it != headers.end() && it->second != cur) {
        cur->left = it->second->left;
        cur->right = it->second->right;
        headers.erase(it);
      }
    }

    return canBuild(cur->left, headers, left_limit, cur->val) &&
           canBuild(cur->right, headers, cur->val, right_limit);
  }
};
