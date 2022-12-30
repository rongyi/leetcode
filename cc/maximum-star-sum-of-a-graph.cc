// https://leetcode.com/problems/maximum-star-sum-of-a-graph/
#include "xxx.hpp"

class Solution {
public:
  int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k) {
    int ret = numeric_limits<int>::min();
    int sz = vals.size();
    vector<vector<int>> neibs(sz);
    for (auto &e : edges) {
      neibs[e[0]].push_back(e[1]);
      neibs[e[1]].push_back(e[0]);
    }
    for (int i = 0; i < sz; ++i) {
      // min pq
      priority_queue<int, vector<int>, greater<int>> pq;
      for (auto &next : neibs[i]) {
        pq.push(vals[next]);
        if (pq.size() > k) {
          pq.pop();
        }
      }
      int cur_sum = vals[i];
      while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        if (cur > 0) {
          cur_sum += cur;
        }
      }
      ret = max(ret, cur_sum);
    }

    return ret;
  }
};
