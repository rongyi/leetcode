// http://leetcode.com/problems/bus-routes/description/
#include "xxx.h"

class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
    // 记录每个station有多少路公交，第一辆公交为0路
    unordered_map<int, unordered_set<int>> station;
    for (int i = 0; i < routes.size(); i++) {
      for (auto &j : routes[i]) {
        // j站台有i路公交停靠
        station[j].insert(i);
      }
    }

    queue<pair<int, int>> bfs;
    bfs.push({S, 0});
    unordered_set<int> visited{S};
    while (!bfs.empty()) {
      int cur_station = bfs.front().first;
      int cur_transfer = bfs.front().second;
      bfs.pop();
      if (cur_station == T) {
        return cur_transfer;
      }
      // 停靠此站台的所有公交
      for (auto &bus : station[cur_station]) {
        for (auto &next_stop : routes[bus]) {
          if (visited.find(next_stop) == visited.end()) {
            visited.insert(next_stop);
            bfs.push({next_stop, cur_transfer + 1});
          }
        }
        // 换乘之后不可达
        // routes[bus].clear();
      }
    }

    return -1;
  }
};
