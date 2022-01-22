// http://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/description/
#include "xxx.hpp"

class Solution {
public:
  // Let's think of the problem in a reverse way: "given a rooted tree, please
  // DFS the tree and print out all the pairs between ancestor and a node"
  // 倒过来就是这道题
  int checkWays(vector<vector<int>> &pairs) {
    unordered_map<int, unordered_set<int>> adj;
    // 一个双向图
    for (auto &p : pairs) {
      adj[p[0]].insert(p[1]);
      adj[p[1]].insert(p[0]);
    }

    priority_queue<pair<int, int>> q;
    for (auto &[x, arr] : adj) {
      q.push({arr.size(), x});
    }

    int n = q.size();
    bool multiple = false;
    // 当前访问过的节点
    unordered_set<int> seen;

    while (!q.empty()) {
      auto [cur_digree, cur] = q.top();
      q.pop();

      // 都是不可能的值
      int root = 0;
      int root_degree = n + 1;
      if (!seen.empty()) {
        // v的父节点是访问过的里面度数最低的那个
        // 因为child还要跟上面建链，度数也高
        for (auto x : adj[cur]) {
          if (adj[x].size() < root_degree && seen.count(x)) {
            root = x;
            root_degree = adj[x].size();
          }
        }
      }

      seen.insert(cur);
      // 没找着，那么当前节点就是root，要求度数为n - 1
      if (root == 0) {
        if (cur_digree != (n - 1)) {
          return 0;
        }
        continue;
      }

      // 要求所有节点都要和root建链
      for (auto x : adj[cur]) {
        if (x == root) {
          continue;
        }
        if (!adj[root].count(x)) {
          return 0;
        }
      }
      // root可以有多个
      if (root_degree == cur_digree) {
        multiple = true;
      }
    }
    if (multiple) {
      return 2;
    }

    return 1;
  }
};
