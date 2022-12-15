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
      // wtf is this?
      // childres[i] means this subtree(including root) number
      // so for all nodes except node 0, we count how many cars we need
      // for current subtree, those cars will cost 1 * cars fuels to uppper node
      // and then for every upper node, we count how many cars we need(including
      // the subtree car) and to move upper layer, also cost (1 * cars) fuels
      // 0----1-----3
      // |    \
      // 5     4
      //        \
      //         2
      // seats = 3
      // childrens[2] = 1 -> one car
      // ...
      // childres[1] = 4 -> need two car, so from node 1 to capital 0 this step
      // need 2 fuels
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
