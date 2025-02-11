// http://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
#include "xxx.hpp"

class Solution {
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
    int INF = 1e6;
    vector<vector<int>> dist = vector<vector<int>>(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
      dist[i][i] = 0;
    }
    for (auto &e : edges) {
      auto v0 = e[0];
      auto v1 = e[1];
      auto w = e[2];
      dist[v0][v1] = w;
      dist[v1][v0] = w;
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    int min_reach = n;
    int ret = 0;
    for (int i = 0; i < n; i++) {
      int cur_reach = 0;
      for (int j = 0; j < n; j++) {
        if (dist[i][j] <= distanceThreshold) {
          cur_reach++;
        }
      }

      if (cur_reach <= min_reach) {
        min_reach = cur_reach;
        ret = i;
      }
    }

    return ret;
  }
  // DFS will not work, see here:
  // https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/discuss/490555/The-Reason-of-DFS-Not-Working-(Explain-Graph-and-Example)
  int findTheCity2(int n, vector<vector<int>> &edges, int distanceThreshold) {
    for (auto &v : edges) {
      weights_[key(v[0], v[1])] = v[2];
      neibs_[v[0]].push_back(v[1]);
      neibs_[v[1]].push_back(v[0]);
    }

    int ret = -1;
    int max_reach = n;
    for (int i = 0; i < n; i++) {
      vector<int> cur_reach;
      unordered_set<int> visited;

      dfs(i, cur_reach, distanceThreshold, visited);

      if (cur_reach.size() <= max_reach) {
        ret = i;
        max_reach = cur_reach.size();
      }
    }

    return ret;
  }

private:
  void dfs(int start, vector<int> &can_reach, int threshold,
           unordered_set<int> &visited) {
    if (visited.find(start) != visited.end()) {
      return;
    }
    visited.insert(start);
    for (auto &n : neibs_[start]) {
      if (visited.find(n) == visited.end() &&
          weights_[key(start, n)] <= threshold) {
        can_reach.push_back(n);
        // goes down
        dfs(n, can_reach, threshold - weights_[key(start, n)], visited);
      }
    }
  }
  string key(int i, int j) {
    if (i <= j) {
      return to_string(i) + "|" + to_string(j);
    }
    return to_string(j) + "|" + to_string(i);
  }

private:
  unordered_map<string, int> weights_;
  unordered_map<int, vector<int>> neibs_;
};

int main() {
  Solution so;
  vector<vector<int>> input{{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
  so.findTheCity(4, input, 4);
}
