// https://leetcode.com/problems/the-time-when-the-network-becomes-idle/
#include "xxx.h"

class Solution {
public:
  int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
    int n = patience.size();
    vector<vector<int>> graph(n);
    // also use like a visited cache
    vector<int> time(n, -1);
    for (auto &e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    // calculate the ttl for each node
    queue<int> q;
    q.push(0);
    time[0] = 0;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (auto &child : graph[cur]) {
        if (time[child] == -1) {
          time[child] = time[cur] + 1;
          q.push(child);
        }
      }
    }
    // ensure node0 time is 0
    /*
    int layer = -1;
    while (!q.empty()) {
      layer++;
      int sz = q.size();
      queue<int> tmp;
      for (int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        time[cur] = layer;
        tmp.push(cur);
      }

      // there are cycle
      //    0
      //  1 -  2
      //  when 1 connect 2, using bfs will get 2's time is 2
      //  but we want 1
      while (!tmp.empty()) {
        auto cur = tmp.front();
        tmp.pop();
        for (auto &child : graph[cur]) {
          if (time[child] == -1) {
            q.push(child);
          }
        }
      }
    }
    */

    int ret = 0;
    for (int i = 1; i < n; ++i) {
      int repeat_send_count = (time[i] * 2 - 1) / patience[i];
      int last_out = repeat_send_count * patience[i];
      int shutup_at = time[i] * 2 + last_out;
      ret = max(ret, shutup_at);
    }

    return ret + 1;
  }
};
