// http://leetcode.com/problems/jump-game-iv/description/
#include "xxx.h"

class Solution {
public:
  int minJumps(vector<int> &arr) {
    const int n = arr.size();
    unordered_map<int, vector<int>> index;
    for (int i = 0; i < n; i++) {
      index[arr[i]].push_back(i);
    }
    vector<bool> visited(n, false);
    visited[0] = true;

    queue<int> q;
    q.push(0);

    int step = 0;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int i = q.front();
        q.pop();
        if (i == n - 1) {
          return step;
        }
        auto &next = index[arr[i]];
        next.push_back(i - 1);
        next.push_back(i + 1);
        for (auto j : next) {
          if (j >= 0 && j < n && !visited[j]) {
            visited[j] = true;
            q.push(j);
          }
        }
        // 所有相等的value只进入队列一次
        // 后面就只选相邻的节点了
        next.clear();
      }
      step++;
    }

    return 0;
  }
};
