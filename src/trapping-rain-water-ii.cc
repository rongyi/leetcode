// http://leetcode.com/problems/trapping-rain-water-ii/description/
#include "xxx.h"

class Solution {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    const int m = heightMap.size();
    if (m == 0) {
      return 0;
    }
    const int n = heightMap[0].size();
    // 小顶堆
    // pair格式： value, index
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    // 把边界塞进来
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
          pq.push({heightMap[i][j], i * n + j});
          visited[i][j] = true;
        }
      }
    }

    int ret = 0;
    int max_height = numeric_limits<int>::min();

    vector<vector<int>> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int height = p.first;
      int i = p.second / n;
      int j = p.second % n;
      max_height = max(max_height, height);

      for (auto d : dir) {
        int ni = i + d[0];
        int nj = j + d[1];
        if (ni >= m || ni < 0 || nj >= n || nj < 0 || visited[ni][nj]) {
          continue;
        }
        visited[ni][nj] = true;

        if (heightMap[ni][nj] < max_height) {
          ret += max_height - heightMap[ni][nj];
        }
        pq.push({heightMap[ni][nj], ni * n + nj});
      }
    }

    return ret;
  }
};
