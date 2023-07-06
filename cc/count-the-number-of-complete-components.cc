// https://leetcode.com/problems/count-the-number-of-complete-components/
#include "xxx.hpp"

class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    vector<int> visited(n, 0);
    vector<vector<int>> neibs(n);
    for (auto &e : edges) {
      neibs[e[0]].push_back(e[1]);
      neibs[e[1]].push_back(e[0]);
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      queue<int> q;
      int group_cnt = 0;
      int edge_cnt = 0;
      q.push(i);

      while (!q.empty()) {
        int sz = q.size();
        for (int j = 0; j < sz; j++) {
          auto cur = q.front();
          q.pop();
          group_cnt++;
          // every edge count twice, so we will
          // divide 2
          edge_cnt += neibs[cur].size();
          for (auto &next : neibs[cur]) {
            if (!visited[next]) {
              visited[next] = true;
              q.push(next);
            }
          }
        }
      }

      if ((group_cnt * (group_cnt - 1) / 2) == edge_cnt / 2) {
        ret++;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{0, 1}, {0, 2}, {1, 2}, {3, 4}};
  so.countCompleteComponents(6, input);
}
