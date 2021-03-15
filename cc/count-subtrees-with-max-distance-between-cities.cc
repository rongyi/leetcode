// http://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/description/
#include "xxx.h"

class Solution {
public:
  // Using Floyd-Warshall algorithm to calculate minimum distance between any
  // node to any other node. Since n <= 15, there is a maximum 2^15 subset of
  // cities numbered from 1 to n. For each of subset of cities: Our subset forms
  // a subtree if and only if number of edges = number of cities - 1 Iterate all
  // pair of cities to calculate number of edges, number of cities, maximum
  // distance between any 2 cities
  vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges) {
    // 节点间的距离最大是n - 1，因为是棵树
    const int inf = n;
    vector<vector<int>> dist(n, vector<int>(n, inf));
    for (auto &e : edges) {
      dist[e[0] - 1][e[1] - 1] = 1;
      dist[e[1] - 1][e[0] - 1] = 1;
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    vector<int> ret(n - 1, 0);
    for (int state = 0; state < (1 << n); state++) {
      int d = maxDistance(state, dist, n);
      if (d > 0) {
        ret[d - 1] += 1;
      }
    }

    return ret;
  }

private:
  int maxDistance(int state, vector<vector<int>> &dist, int n) {
    int num_edges = 0;
    int num_cities = 0;
    int max_dist = 0;
    for (int i = 0; i < n; ++i) {
      // 不含这个节点
      if (((state >> i) & 1) == 0) {
        continue;
      }
      num_cities += 1;
      for (int j = i + 1; j < n; ++j) {
        if (((state >> j) & 1) == 0) {
          continue;
        }

        if (dist[i][j] == 1) {
          num_edges += 1;
        }

        max_dist = max(max_dist, dist[i][j]);
      }
    }
    if (num_edges != num_cities - 1) {
      return 0;
    }

    return max_dist;
  }
};
