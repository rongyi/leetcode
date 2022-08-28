// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
#include "xxx.hpp"

class Solution {
public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    int ret = -1;
    int min_max_dist = numeric_limits<int>::max();
    int sz = edges.size();
    vector<int> m1(sz, -1);
    vector<int> m2(sz, -1);

    dfs(node1, 0, edges, m1);
    dfs(node2, 0, edges, m2);

    for (int i = 0; i < sz; ++i) {
      if (min(m1[i], m2[i]) >= 0 && max(m1[i], m2[i]) < min_max_dist) {
        min_max_dist = max(m1[i], m2[i]);
        ret = i;
      }
    }

    return ret;
  }
  void dfs(int cur, int dist, vector<int> &edges, vector<int> &memo) {
    while (cur != -1 && memo[cur] == -1 /*incase loop*/) {
      memo[cur] = dist++;
      cur = edges[cur];
    }
  }
};
