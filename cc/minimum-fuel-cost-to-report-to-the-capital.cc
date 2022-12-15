// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/
#include "xxx.hpp"

class Solution {
public:
  long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
    // nodes number
    int sz = roads.size() + 1;

    vector<vector<int>> neibs(sz);
    for (auto &r : roads) {
      neibs[r[0]].push_back(r[1]);
      neibs[r[1]].push_back(r[0]);
    }
    // childrens include it self
    vector<int> childrens(sz, 0);

    vector<int> visited(sz, 0);
    for (auto &next : neibs[0]) {
      dfs(next, 0, childrens, neibs);
    }
    long long fuels = 0;
    for (int i = 1; i < sz; ++i) {
      fuels += (childrens[i] + seats - 1) / seats;
    }

    return fuels;
  }

private:
  int dfs(int cur, int parent, vector<int> &childres,
          vector<vector<int>> &neibs) {
    int ret = 1;
    for (auto &next : neibs[cur]) {
      if (next == parent) {
        continue;
      }
      ret += dfs(next, cur, childres, neibs);
    }
    childres[cur] = ret;
    return ret;
  }
};
