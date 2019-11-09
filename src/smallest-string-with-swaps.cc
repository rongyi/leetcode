// http://leetcode.com/problems/smallest-string-with-swaps/description/
#include "xxx.h"

class Solution {
public:
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    vector<int> ds(s.size(), -1);
    vector<vector<int>> group(s.size());

    for (auto &p : pairs) {
      auto i = find(ds, p[0]);
      int j = find(ds, p[1]);
      if (i != j) {
        ds[j] = i;
      }
    }
    for (int i = 0; i < s.size(); ++i) {
      // group together
      group[find(ds, i)].push_back(i);
    }
    for (auto cur_group : group) {
      string g{};
      for (auto id : cur_group) {
        g += s[id];
      }
      sort(g.begin(), g.end());
      for (auto i = 0; i < cur_group.size(); ++i) {
        s[cur_group[i]] = g[i];
      }
    }
    return s;
  }

private:
  // union find
  int find(vector<int> &ds, int i) {
    if (ds[i] < 0) {
      return i;
    }
    // cache
    ds[i] = find(ds, ds[i]);
    return ds[i];
  }
};
