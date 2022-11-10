// https://leetcode.com/problems/number-of-good-paths/
#include "xxx.hpp"

class Solution {
public:
  int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
    int sz = vals.size();
    vector<int> parent(sz, 0);
    iota(parent.begin(), parent.end(), 0);
    vector<int> count(sz, 1);
    // intiail single node as one group
    int ret = sz;
    sort(edges.begin(), edges.end(), [&](vector<int> &l, vector<int> &r) {
      return max(vals[l[0]], vals[l[1]]) < max(vals[r[0]], vals[r[1]]);
    });
    for (auto &e : edges) {
      auto p1 = find(parent, e[0]);
      auto p2 = find(parent, e[1]);
      if (vals[p1] == vals[p2]) {
        ret += count[p1] * count[p2];
        // merge
        count[p1] += count[p2];
        parent[p2] = p1;
      } else {
        // so each parent denote there group's max value
        if (vals[p1] > vals[p2]) {
          parent[p2] = p1;
        } else {
          parent[p1] = p2;
        }
      }
    }

    return ret;
  }

private:
  int find(vector<int> &parent, int i) {
    if (parent[i] == i) {
      return i;
    }
    return parent[i] = find(parent, parent[i]);
  }
};
