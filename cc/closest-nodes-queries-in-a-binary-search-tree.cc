// https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/
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
  vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
    vector<int> lst;
    sorted(root, lst);

    vector<vector<int>> ret;
    // cout << "here" << endl;
    for (auto &q : queries) {
      auto it = lower_bound(lst.begin(), lst.end(), q);
      // means too big
      if (it == lst.end()) {
        ret.push_back({lst.back(), -1});
      } else {
        // found the num
        if (*it == q) {
          ret.push_back({q, q});
        } else {
          // no? ok, then *it is the next bigger one
          // we need to find the smaller one
          // if it is already at begin, there's no smaller one
          if (it != lst.begin()) {
            ret.push_back({*prev(it), *it});
          } else {
            ret.push_back({-1, *it});
          }
        }
      }
    }

    return ret;
  }

private:
  void sorted(TreeNode *cur, vector<int> &lst) {
    if (!cur) {
      return;
    }
    sorted(cur->left, lst);
    lst.push_back(cur->val);
    sorted(cur->right, lst);
  }
};
