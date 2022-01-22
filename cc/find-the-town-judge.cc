// http://leetcode.com/problems/find-the-town-judge/description/
#include "xxx.hpp"

class Solution {
public:
  int findJudge(int N, vector<vector<int>> &trust) {
    unordered_set<int> all_nodes;
    for (int i = 1; i <= N; i++) {
      all_nodes.insert(i);
    }
    unordered_map<int, unordered_set<int>> graph;
    unordered_set<int> trust_others;
    for (auto &t : trust) {
      graph[t[0]].insert(t[1]);
      trust_others.insert(t[0]);
    }
    unordered_set<int> candi;
    for (auto cur_node : all_nodes) {
      if (graph.find(cur_node) != graph.end()) {
        continue;
      }
      // this node trust no other
      bool all_trust = true;
      for (int i = 1; i <= N; i++) {
        if (i == cur_node) {
          continue;
        }
        if (graph.find(i) == graph.end() || graph[i].find(cur_node) == graph[i].end()) {
          all_trust = false;
          break;
        }
      }
      if (all_trust) {
        candi.insert(cur_node);
      }
    }
    if (candi.size() != 1) {
      return -1;
    }
    return *candi.begin();
  }
  void dfs(unordered_map<int, int> &graph, unordered_set<int> &candi, int cur_start, unordered_set<int> &visited) {
    // fuck, there is a loop
    if (visited.find(cur_start) != visited.end()) {
      return;
    }
    // this node trust no one, so it is a judge candidate
    if (graph.find(cur_start) == graph.end()) {
      candi.insert(cur_start);
      return;
    }
    visited.insert(cur_start);
    dfs(graph, candi, graph[cur_start], visited);
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{1, 2}, {2, 3}};
  cout << so.findJudge(3, input) << endl;
  return 0;
}
