// http://leetcode.com/problems/cheapest-flights-within-k-stops/description/
#include "xxx.hpp"

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
    int res = numeric_limits<int>::max();
    unordered_map<int, vector<vector<int>>> node_flight;
    unordered_set<int> visited{src};
    for (auto flight : flights) {
      node_flight[flight[0]].push_back({flight[1], flight[2]});
    }
    helper(node_flight, src, dst, K, visited, 0, res);
    return (res == numeric_limits<int>::max()) ? -1 : res;
  }
  void helper(unordered_map<int, vector<vector<int>>> &node_flight, int cur,
              int dst, int K, unordered_set<int> &visited, int out, int &res) {
    if (cur == dst) {
      res = out;
      return;
    }
    if (K < 0)
      return;
    // dst and weight map
    // 经典的for循环加递归
    for (auto dwm : node_flight[cur]) {
      // 打环了，或者当前飞行代价已经高了
      if (visited.count(dwm[0]) || out + dwm[1] > res) {
        continue;
      }
      visited.insert(dwm[0]);
      helper(node_flight, dwm[0], dst, K - 1, visited, out + dwm[1], res);
      visited.erase(dwm[0]);
    }
  }
};
