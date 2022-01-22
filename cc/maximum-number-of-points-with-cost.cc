// https://leetcode.com/problems/maximum-number-of-points-with-cost/
#include "xxx.hpp"
class Solution {
public:
  long long maxPoints(vector<vector<int>> &points) {
    int m = points.size();
    int n = points[0].size();
    // left and right are just the prev value calculated from one
    // direction, so we can just pick the one of the biggest in O(1)
    vector<long long> from_left(n, 0);
    vector<long long> from_right(n, 0);
    vector<long long> prev =
        vector<long long>(points[0].begin(), points[0].end());
    auto update_two_direction = [](vector<long long> &prev,
                                   vector<long long> &l, vector<long long> &r) {
      int sz = prev.size();
      l[0] = prev[0];
      r[sz - 1] = prev[sz - 1];
      for (int i = 1; i < prev.size(); ++i) {
        // why just compare to left should do
        // others in far distance is already
        // eliminated by prev comparsion
        l[i] = max(prev[i], l[i - 1] - 1);
      }
      for (int i = sz - 2; i >= 0; --i) {
        r[i] = max(prev[i], r[i + 1] - 1);
      }
    };

    update_two_direction(prev, from_left, from_right);
    for (int i = 1; i < m; ++i) {
      vector<long long> next(n, 0);
      for (int j = 0; j < n; ++j) {
        next[j] = max(from_left[j], from_right[j]) + points[i][j];
      }
      prev = next;
      update_two_direction(prev, from_left, from_right);
    }

    return *max_element(prev.begin(), prev.end());
  }
};
