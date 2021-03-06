// http://leetcode.com/problems/maximum-number-of-visible-points/description/
#include "xxx.h"

class Solution {
public:
  // Here are the steps:

  // 1. convert all coordinates to radians
  // 2. sort the array
  // 3. use sliding window to find the longest window that satisfies arr[r] - arr[l] <= angle.
  int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &me) {
    vector<double> angs;
    int max_points = 0;
    int overlap = 0;
    for (auto &p : points) {
      if (p[0] == me[0] && p[1] == me[1]) {
        ++overlap;
      } else {
        angs.push_back(atan2(p[1] - me[1], p[0] - me[0]) * 180 / M_PI);
      }
    }
    sort(angs.begin(), angs.end());
    int sz = angs.size();
    for (int i = 0, j = 0; i < sz * 2; ++i) {
      if (360 * (i >= sz) + angs[i % sz] - 360 * (j >= sz) - angs[j % sz] >
          angle) {
        ++j;
      }
      max_points = max(max_points, i - j + 1);
    }

    return max_points + overlap;
  }
};
