// http://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
#include "xxx.hpp"

class Solution {
public:
  // 换算成图来做
  vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
    unordered_map<int, unordered_set<int>> graph;
    inorder(root, nullptr, graph);
    queue<int> q;
    q.push(target->val);

    int dis = 0;

    vector<int> ret;

    unordered_set<int> visited;
    // visited.insert(target->val);

    while (!q.empty()) {
      int cnt = q.size();
      for (int i = 0; i < cnt; i++) {
        auto cur = q.front();
        visited.insert(cur);
        q.pop();
        if (dis == K) {
          ret.push_back(cur);
        } else {
          // continue to push to queue
          for (auto nei : graph[cur]) {
            if (visited.find(nei) == visited.end()) {
              q.push(nei);
            }
          }
        }
      }

      dis++;
    }

    return ret;
  }

private:
  void inorder(TreeNode *cur, TreeNode *parent,
               unordered_map<int, unordered_set<int>> &graph) {
    if (!cur) {
      return;
    }
    if (parent) {
      graph[parent->val].insert(cur->val);
      graph[cur->val].insert(parent->val);
    }
    inorder(cur->left, cur, graph);
    inorder(cur->right, cur, graph);
  }
};
