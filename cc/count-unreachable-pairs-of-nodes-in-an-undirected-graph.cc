// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
#include "xxx.hpp"

class Solution {
public:
  long long countPairs(int n, vector<vector<int>> &edges) {
    vector<bool> visited(n, false);
    map<int, vector<int>> neibs;
    for (auto &e : edges) {
      neibs[e[0]].push_back(e[1]);
      neibs[e[1]].push_back(e[0]);
    }
    long long ret = (long long)n * (n - 1) / 2;
    // group num will be pushed back in
    for (int i = 0; i < n; ++i) {
      if (visited[i]) {
        continue;
      }
      queue<int> q;
      q.push(i);
      visited[i] = true;
      int cur_group = 0;
      while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        cur_group++;
        for (auto next_node : neibs[cur]) {
          if (!visited[next_node]) {
            visited[next_node] = true;
            q.push(next_node);
          }
        }
      }
      //groups.push_back(cur_group);
      ret -= (long long)cur_group * (cur_group - 1) / 2;
    }


    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input {
    {0, 2}, {0, 5}, {2, 4}, {1, 6}, { 5, 4 }
  };
  so.countPairs(7, input);
}
