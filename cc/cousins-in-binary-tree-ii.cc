// https://leetcode.com/problems/cousins-in-binary-tree-ii/
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
class SolutionTLE {
public:
  TreeNode *replaceValueInTree(TreeNode *root) {
    levelOrder(root, nullptr, 0);
    Update(root, nullptr, 0);

    return root;
  }

private:
  void levelOrder(TreeNode *cur, TreeNode *parent, int level) {
    if (!cur) {
      return;
    }
    level_with_parent_[level].push_back({parent, cur->val});
    levelOrder(cur->left, cur, level + 1);
    levelOrder(cur->right, cur, level + 1);
  }
  void Update(TreeNode *cur, TreeNode *parent, int level) {
    if (!cur) {
      return;
    }
    int sum = 0;
    for (auto &pv : level_with_parent_[level]) {
      if (pv.first == parent) {
        continue;
      }
      sum += pv.second;
    }

    cur->val = sum;

    Update(cur->left, cur, level + 1);
    Update(cur->right, cur, level + 1);
  }

private:
  map<int, vector<pair<TreeNode *, int>>> level_with_parent_;
};

class Solution {
public:
  TreeNode *replaceValueInTree(TreeNode *root) {
    root->val = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int sz = q.size();
      int next_level_sum = 0;
      // bfs while collect next level sum
      vector<TreeNode *> cur_level;
      for (int i = 0; i < sz; i++) {
        auto cur = q.front();
        q.pop();
        cur_level.push_back(cur);
        if (cur->left) {
          q.push(cur->left);
          next_level_sum += cur->left->val;
        }
        if (cur->right) {
          q.push(cur->right);
          next_level_sum += cur->right->val;
        }
      }
      // update next level
      for (auto &cur : cur_level) {
        int val = next_level_sum;
        if (cur->left) {
          val -= cur->left->val;
        }
        if (cur->right) {
          val -= cur->right->val;
        }
        if (cur->left) {
          cur->left->val = val;
        }
        if (cur->right) {
          cur->right->val = val;
        }
      }
    }
    return root;
  }
};
