// https://leetcode.com/problems/longest-cycle-in-a-graph/
#include "xxx.hpp"

class Solution {
public:
  int longestCycle(vector<int> &edges) {
    int ret = -1;
    int sz = edges.size();
    vector<pair<int, int>> memo(sz, {-1, -1});
    vector<int> visited(sz, false);

    for (int i = 0; i < sz; ++i) {
      // i as start point
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      for (int j = i, dist = 0; j != -1; j = edges[j]) {
        visited[j] = true;

        auto [cur_dist, start] = memo[j];
        if (start == -1) {
          memo[j] = {dist++, i};
        } else {
          if (start == i) {
            ret = max(ret, dist - cur_dist);
          }
          // already in a loop that start from other node
          break;
        }
      }
    }

    return ret;
  }
};
