// http://leetcode.com/problems/smallest-string-with-swaps/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/smallest-string-with-swaps/discuss/388257/C%2B%2B-with-picture-union-find
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    // disjoint set
    vector<int> ds(s.size(), -1);
    // group find set together
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
      string tmp{};
      for (auto id : cur_group) {
        tmp += s[id];
      }
      sort(tmp.begin(), tmp.end());
      for (auto i = 0; i < cur_group.size(); ++i) {
        s[cur_group[i]] = tmp[i];
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
    // cache, every element will know its group
    ds[i] = find(ds, ds[i]);
    return ds[i];
  }
};
