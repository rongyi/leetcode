// https://leetcode.com/problems/detonate-the-maximum-bombs/
#include "xxx.hpp"

class Solution {
public:
  int maximumDetonation(vector<vector<int>> &bombs) {
    int sz = bombs.size();
    int ret = 0;
    vector<vector<int>> edges(sz);
    for (int i = 0; i < sz; ++i) {
      long long x1 = bombs[i][0];
      long long y1 = bombs[i][1];
      long long rr = (long long)bombs[i][2] * bombs[i][2];
      for (int j = 0; j < sz; ++j) {
        long long x2 = bombs[j][0];
        long long y2 = bombs[j][1];
        long long dx = x1 - x2;
        long long dy = y1 - y2;
        // I can make all those bombs to explode(in my range)
        // that mean i -> j has an edge
        if (dx * dx + dy * dy <= rr) {
          edges[i].push_back(j);
        }
      }
    }
    for (int i = 0; i < sz && ret < sz; ++i) {
      bitset<100> curset;
      ret = max(dfs(i, edges, curset), ret);
    }

    return ret;
  }

private:
  int dfs(int cur, vector<vector<int>> &edges, bitset<100> &curset) {
    if (!curset[cur]) {
      curset[cur] = true;
      for (auto e : edges[cur]) {
        dfs(e, edges, curset);
      }
    }
    return curset.count();
  }
};
