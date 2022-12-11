// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
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
  int minimumOperations(TreeNode *root) {
    vector<vector<int>> levels;
    level(root, levels, 1);
    int ret = 0;
    for (auto &l : levels) {
      vector<int> ids(l.size(), 0);
      iota(ids.begin(), ids.end(), 0);
      sort(ids.begin(), ids.end(), [&](int i, int j) { return l[i] < l[j]; });
      for (int i = 0; i < ids.size(); ++i) {
        while (ids[i] != i) {
          // put value at 'i''s pos to its final pos
          // i and ids[i] swap
          // e.g. if i is 2 and ids[2] is 7
          // means 7 should be at ids[7]
          // so we put 7 to it's destination ids[7]
          // and swap the value ids[7] to here
          // and then check again
          // if still not the pos, we swap again
          swap(ids[i], ids[ids[i]]);
          ret += 1;
        }
      }
    }
    return ret;
  }

private:
  void level(TreeNode *cur, vector<vector<int>> &ls, int depth) {
    if (!cur) {
      return;
    }
    if (ls.size() < depth) {
      ls.push_back({});
    }
    ls[depth - 1].push_back(cur->val);
    level(cur->left, ls, depth + 1);
    level(cur->right, ls, depth + 1);
  }
};
