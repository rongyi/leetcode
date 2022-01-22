// http://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
    // 每一个节点的child频率统计，26个字符
    vector<vector<int>> freq(n, vector<int>(26, 0));
    // 至少都包含它自己的label
    vector<int> ret(n, 1);

    vector<vector<int>> graph(n);
    for (int i = 0; i < edges.size(); ++i) {
      graph[edges[i][0]].push_back(edges[i][1]);
      graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n, false);

    // The root of the tree is the node 0
    dfs(graph, visited, 0, ret, freq, labels);

    return ret;
  }

private:
  // current visited node
  void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node,
           vector<int> &ret, vector<vector<int>> &freq, string &label) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;

    for (auto &neib : graph[node]) {
      if (visited[neib]) {
        continue;
      }
      dfs(graph, visited, neib, ret, freq, label);
      // 子节点都访问过了，现在更新当前节点
      ret[node] += freq[neib][label[node] - 'a'];

      // 子节点频率汇总到当前节点上来
      for (int i = 0; i < 26; ++i) {
        freq[node][i] += freq[neib][i];
      }
    }

    // 更新当前节点，这些值是给父节点用的
    freq[node][label[node] - 'a']++;
  }
};
