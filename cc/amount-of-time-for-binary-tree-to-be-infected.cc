// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
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
  int amountOfTime(TreeNode *root, int start) {
    map<int, vector<int>> nodes;
    preorder(root, nodes);

    // make sure the first layer is 0
    int layer = -1;
    map<int, bool> visited;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        visited[cur] = true;
        for (auto &n : nodes[cur]) {
          if (!visited[n]) {
            q.push(n);
          }
        }
      }
      layer++;
    }

    return layer;
  }

private:
  void preorder(TreeNode *cur, map<int, vector<int>> &nodes) {
    if (!cur) {
      return;
    }
    if (cur->left) {
      nodes[cur->val].push_back(cur->left->val);
      nodes[cur->left->val].push_back(cur->val);
    }
    if (cur->right) {
      nodes[cur->val].push_back(cur->right->val);
      nodes[cur->right->val].push_back(cur->val);
    }
    preorder(cur->left, nodes);
    preorder(cur->right, nodes);
  }
};
