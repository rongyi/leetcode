// http://leetcode.com/problems/trapping-rain-water-ii/description/
#include "xxx.h"

class Solution {
public:
  // 1 1 1 1
  // 1 0 x 1
  // 1 1 1 1
  // 以这个为例，四周先入优先级队列，当要访问到0这个节点的时候其实
  // x值是大是小都无所谓了，因为大了，正好作为围栏围起来，而且这个0
  // 周围的木桶最矮的就是1, 如果小了不影响0这个点盛水，因为四周大范围
  // 还有一个木桶。而这个就是用优先级队列的好处。

  // 对于某一个当前的结点X, 如果它的四周有一个结点Y没有被访问过且elevation更低,
  // 那说明什么? 说明Y四周不管是紧邻还是大范围总是存在一个木桶围住它
  // 而Y所能盛水的量只能是上下左右里面最低的一个, 也就是X.
  // 这也是为什么需要Heap的原因.
  int trapRainWater(vector<vector<int>> &heightMap) {
    const int m = heightMap.size();
    if (m == 0) {
      return 0;
    }
    const int n = heightMap[0].size();
    // 小顶堆
    // pair格式： value, index
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

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

int main() {
  Solution so;
  vector<vector<int>> input{{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
  auto ret = so.trapRainWater(input);
  cout << ret << endl;
}
