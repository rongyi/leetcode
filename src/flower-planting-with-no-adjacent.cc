// http://leetcode.com/problems/flower-planting-with-no-adjacent/description/
#include "xxx.h"

class Solution {
public:
  vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {
    vector<int> ret(N, 0);

    vector<vector<int>> graph(N, vector<int>());

    // 全部平移到0 .. N - 1区间来
    for (auto &p : paths) {
      graph[p[0] - 1].push_back(p[1] - 1);
      graph[p[1] - 1].push_back(p[0] - 1);
    }

    for (int i = 0; i < N; ++i) {
      bool color[5] = {};
      // 看邻接点颜色
      for (auto nei : graph[i]) {
        color[ret[nei]] = true;
      }
      for (int c = 1; c < 5; ++c) {
        if (!color[c]) {
          ret[i] = c;
          break;
        }
      }
    }

    return ret;
  }
};
