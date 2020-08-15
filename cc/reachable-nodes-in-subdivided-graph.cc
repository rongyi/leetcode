// http://leetcode.com/problems/reachable-nodes-in-subdivided-graph/description/
#include "xxx.h"

class Solution {
public:
  int reachableNodes(vector<vector<int>> &edges, int M, int N) {
    unordered_map<int, unordered_map<int, int>> cache;
    for (auto cur_vec : edges) {
      cache[cur_vec[0]][cur_vec[1]] = cur_vec[2];
      cache[cur_vec[1]][cur_vec[0]] = cur_vec[2];
    }
    priority_queue<pair<int, int>> pq;
    pq.push({M, 0});
    unordered_map<int, int> visited;

    while (!pq.empty()) {
      auto left_moves = pq.top().first;
      auto cur_node = pq.top().second;
      pq.pop();
      if (visited.find(cur_node) == visited.end()) {
        visited[cur_node] = left_moves;
        // find cur node neighbor and see if we can visit them
        for (auto cur_neis : cache[cur_node]) {
          int check_move = left_moves - cur_neis.second - 1;
          // yes, we can visit this node
          if (visited.find(cur_neis.first) == visited.end() &&
              check_move >= 0) {
            pq.push({check_move, cur_neis.first});
          }
        }
      }
    }
    int ret = visited.size();
    for (auto &vec : edges) {
      // 还剩多少步就能走多少个，但两个加起来不可能比总数多
      int a = visited.find(vec[0]) == visited.end() ? 0 : visited[vec[0]];
      int b = visited.find(vec[1]) == visited.end() ? 0 : visited[vec[1]];
      ret += min(a + b, vec[2]);
    }

    return ret;
  }
};
