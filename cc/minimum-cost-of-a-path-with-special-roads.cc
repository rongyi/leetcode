// https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/
#include "xxx.hpp"

class Solution {
public:
  int minimumCost(vector<int> &start, vector<int> &target,
                  vector<vector<int>> &specialRoads) {
    int startx = start[0];
    int starty = start[1];
    int targetx = target[0];
    int targety = target[1];
    // {pathweight, index in specialRoads}
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    int sz = specialRoads.size();
    vector<int> dp(sz, numeric_limits<int>::max());
    // roads: [startx, starty, endx, endy, weight]
    //           0       1      2     3      4
    // go though the endpoint
    for (int i = 0; i < sz; i++) {
      auto dist = abs(specialRoads[i][2] - targetx);
      dist += abs(specialRoads[i][3] - targety);
      pq.push({dist, i});
    }

    while (!pq.empty()) {
      int cost = pq.top().first;
      int idx = pq.top().second;
      pq.pop();
      if (dp[idx] != numeric_limits<int>::max()) {
        continue;
      }
      dp[idx] = cost;
      for (int i = 0; i < sz; i++) {
        if (i == idx) {
          continue;
        }
        // use current path add the current weight
        auto dist = cost + specialRoads[idx][4];
        // and the distance from the start point of current
        // and the previous endpoint
        dist += abs(specialRoads[i][2] - specialRoads[idx][0]);
        dist += abs(specialRoads[i][3] - specialRoads[idx][1]);

        pq.push({dist, i});
      }
    }
    int ret = abs(startx - targetx) + abs(starty - targety);
    for (int i = 0; i < sz; i++) {
      // start point to current start
      auto dist = abs(startx - specialRoads[i][0]);
      dist += abs(starty - specialRoads[i][1]);
      // and its weight + left dp
      dist += specialRoads[i][4] + dp[i];
      ret = min(ret, dist);
    }

    return ret;
  }
};
