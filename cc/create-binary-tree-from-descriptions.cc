// https://leetcode.com/problems/create-binary-tree-from-descriptions/
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
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    // first find the root, the indegree is 0
    map<int, int> in;
    // left put 0, right put in 1
    map<int, array<int, 2>> graph;
    set<int> nodes;
    for (auto &d : descriptions) {
      auto parent = d[0];
      auto child = d[1];
      auto is_left = d[2];
      // left idex: 0, right index: 1
      graph[parent][1 - is_left] = child;
      ++in[child];
      nodes.insert(parent);
      nodes.insert(child);
    }
    // find the root
    int root_val = -1;
    for (auto &cur : nodes) {
      if (in[cur] == 0) {
        root_val = cur;
        break;
      }
    }
    // build tree recusively
    return dfs(root_val, graph);
  }

private:
  TreeNode *dfs(int cur_val, map<int, array<int, 2>> &graph) {
    TreeNode *ret = new TreeNode(cur_val);

    auto child_lst = graph[cur_val];
    if (child_lst[0] > 0) {
      ret->left = dfs(child_lst[0], graph);
    }
    if (child_lst[1] > 0) {
      ret->right = dfs(child_lst[1], graph);
    }

    return ret;
  }
};
