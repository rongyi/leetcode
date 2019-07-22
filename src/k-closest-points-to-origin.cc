// http://leetcode.com/problems/k-closest-points-to-origin/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
    using pt = vector<int>;
    unordered_map<int, vector<pt>> distance;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &p : points) {
      auto cur_dist = p[0] * p[0] + p[1] * p[1];
      pq.push(cur_dist);
      distance[cur_dist].push_back(p);
    }
    int cur_count = 0;
    vector<vector<int>> ret;
    while (cur_count < K) {
      auto cur_dis = pq.top();
      pq.pop();
      auto cur_points = distance[cur_dis];
      for (int i = 0; i < cur_points.size() && cur_count < K;
           ++i, ++cur_count) {
        ret.push_back(cur_points[i]);
      }
    }
    return ret;
  }
};
