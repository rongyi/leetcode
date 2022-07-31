// https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/discuss/2202551/Two-Loops
  int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
    int previd = 0;
    int ret = numeric_limits<int>::max();
    vector<vector<int>> group(nums.size());
    for (auto &e : edges) {
      group[e[0]].push_back(e[1]);
      group[e[1]].push_back(e[0]);
    }
    int all = dfs(nums, group, 0, -1, previd);
    for (int i = 0; i < edges.size(); ++i) {
      for (int j = i + 1; j < edges.size(); ++j) {
        // https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/discuss/2198665/Python-3-Explanation-with-pictures
        // the graph can be easy understood
        // the total part, included?
        int p1 = j < last_[i] ? all ^ dp_[i] : all ^ dp_[i] ^ dp_[j];
        // the i part
        int p2 = j < last_[i] ? dp_[i] ^ dp_[j] : dp_[i];
        // the j part is dp_[j]
        ret = min(ret, max({p1, p2, dp_[j]}) - min({p1, p2, dp_[j]}));
      }
    }
    return ret;
  }
  int dfs(vector<int> &nums, vector<vector<int>> &group, int cur, int parent,
          int &previd) {
    int ret = nums[cur];
    for (auto j : group[cur]) {
      if (j != parent) {
        int id = previd++;
        dp_[id] = dfs(nums, group, j, cur, previd);
        last_[id] = previd;
        ret ^= dp_[id];
      }
    }

    return ret;
  }

private:
  int dp_[1000] = {};
  // last id in this sub tree
  int last_[1000] = {};
};
