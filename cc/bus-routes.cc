// http://leetcode.com/problems/bus-routes/description/
#include "xxx.hpp"

class Solution {
public:
  int numBusesToDestinationTLE(vector<vector<int>> &routes, int S, int T) {
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

  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {
    if (source == target) {
      return 0;
    }

    set<int> all_stops;
    int max_stop = -1;
    for (auto &route : routes) {
      for (auto &stop : route) {
        max_stop = max(max_stop, stop);
        all_stops.insert(stop);
      }
    }

    if (!all_stops.count(source) || !all_stops.count(target)) {
      return -1;
    }

    vector<int> min_to_reach(max_stop + 1, numeric_limits<int>::max());
    min_to_reach[source] = 0;
    int sz = routes.size();

    bool flag = true;

    while (flag) {
      flag = false;
      for (auto &route : routes) {
        // find th minimum stop in this group
        // so other destination in this group
        // can be reached by one more stop
        // and we loop all routes
        // if one round we find new destination
        // we continue this action
        int min_step = sz + 1;
        for (auto &stop : route) {
          min_step = min(min_step, min_to_reach[stop]);
        }

        min_step += 1;

        for (auto &stop : route) {
          if (min_to_reach[stop] > min_step) {
            min_to_reach[stop] = min_step;
            flag = true;
          }
        }
      }
    }

    if (min_to_reach[target] < sz + 1) {
      return min_to_reach[target];
    }

    return -1;
  }
};
