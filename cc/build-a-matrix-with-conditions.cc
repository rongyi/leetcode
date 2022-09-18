// https://leetcode.com/problems/build-a-matrix-with-conditions/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                                  vector<vector<int>> &colConditions) {
    auto rows = topsort(k, rowConditions);
    auto cols = topsort(k, colConditions);

    if (rows.empty() || cols.empty()) {
      return {};
    }
    // rows and cols will define each nodes index
    vector<pair<int, int>> idx(k);
    // each node's x, y is not updated at the same time
    for (int i = 0; i < k; ++i) {
      // means num at this postion's x pos is i
      idx[rows[i] - 1].first = i;
      // means num at this postion's y pos is i
      idx[cols[i] - 1].second = i;
    }
    vector<vector<int>> ret(k, vector<int>(k, 0));
    for (int i = 0; i < k; ++i) {
      ret[idx[i].first][idx[i].second] = i + 1;
    }

    return ret;
  }

private:
  vector<int> topsort(int k, vector<vector<int>> &conditions) {
    vector<vector<int>> nodes(k + 1);
    vector<int> indgree(k + 1, 0);

    for (auto &edge : conditions) {
      nodes[edge[0]].push_back(edge[1]);
      indgree[edge[1]]++;
    }
    queue<int> q;
    for (int i = 1; i <= k; ++i) {
      if (indgree[i] == 0) {
        q.push(i);
      }
    }

    int cnt = 0;
    vector<int> ret;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      cnt++;
      ret.push_back(cur);

      for (auto &nex : nodes[cur]) {
        indgree[nex]--;

        if (indgree[nex] == 0) {
          q.push(nex);
        }
      }
    }

    if (cnt == k) {
      return ret;
    }

    return {};
  }
};
