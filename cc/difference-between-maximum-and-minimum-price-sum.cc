// https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/
#include "xxx.hpp"

class Solution {
public:
  long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price) {
    vector<vector<int>> neibs(n);

    for (auto &e : edges) {
      neibs[e[0]].push_back(e[1]);
      neibs[e[1]].push_back(e[0]);
    }
    // start from any node
    vector<long long> path_random(n, 0);
    path_random[0] = price[0];
    dfs(0, -1, neibs, path_random, price);

    auto max_u = max_element(path_random.begin(), path_random.end()) -
                 path_random.begin();

    vector<long long> path_fromu(n, 0);
    path_fromu[max_u] = price[max_u];

    dfs(max_u, -1, neibs, path_fromu, price);
    auto max_v =
        max_element(path_fromu.begin(), path_fromu.end()) - path_fromu.begin();

    vector<long long> path_fromv(n, 0);
    path_fromv[max_v] = price[max_v];
    dfs(max_v, -1, neibs, path_fromv, price);

    long long ret = 0;

    for (int i = 0; i < n; ++i) {
      ret = max(ret, path_fromu[i] - price[i]);
      ret = max(ret, path_fromv[i] - price[i]);
    }

    return ret;
  }

private:
  void dfs(int cur, int parent, vector<vector<int>> &neibs,
           vector<long long> &path, vector<int> &prices) {
    for (auto &next : neibs[cur]) {
      if (next == parent) {
        continue;
      }
      path[next] = path[cur] + prices[next];
      dfs(next, cur, neibs, path, prices);
    }
  }
};
