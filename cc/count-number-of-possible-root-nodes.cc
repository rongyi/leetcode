// https://leetcode.com/problems/count-number-of-possible-root-nodes/
#include "xxx.hpp"

class Solution {
public:
  // high quality problem!
  int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses,
                int k) {
    int sz = edges.size() + 1;
    map<pair<int, int>, bool> gscache;
    // for better find
    for (auto &g : guesses) {
      gscache[{g[0], g[1]}] = true;
    }
    total_valid_ = 0;

    map<int, vector<int>> neibs;
    for (auto &e : edges) {
      neibs[e[0]].push_back(e[1]);
      neibs[e[1]].push_back(e[0]);
    }

    vector<int> visited(sz, 0);
    // let's start with node 0 as root to get the base number count;
    int base_cnt = dfs(neibs, gscache, visited, 0);
    // reset visited
    fill(visited.begin(), visited.end(), 0);
    reverseWhileDfs(neibs, gscache, visited, 0, base_cnt, k);

    return total_valid_;
  }

private:
  void reverseWhileDfs(map<int, vector<int>> &neibs,
                       map<pair<int, int>, bool> &guesses, vector<int> &visited,
                       int cur, int base_cnt, int k) {
    if (base_cnt >= k) {
      total_valid_++;
    }
    visited[cur] = 1;
    for (auto &nei : neibs[cur]) {
      if (!visited[nei]) {
        reverseWhileDfs(neibs, guesses, visited, nei,
                        base_cnt - guesses.count({cur, nei}) +
                            guesses.count({nei, cur}),
                        k);
      }
    }
  }

  int dfs(map<int, vector<int>> &neibs, map<pair<int, int>, bool> &guesses,
          vector<int> &visited, int cur) {
    int cnt = 0;
    visited[cur] = 1;

    for (auto &nei : neibs[cur]) {
      if (!visited[nei]) {
        // we find a way from cur -> nei
        if (guesses.count({cur, nei})) {
          cnt += 1;
        }
        cnt += dfs(neibs, guesses, visited, nei);
      }
    }

    return cnt;
  }

private:
  int total_valid_;
};
