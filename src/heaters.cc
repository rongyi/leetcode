// http://leetcode.com/problems/heaters/description/
#include "xxx.h"

class Solution {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    vector<int> distance(houses.size(), numeric_limits<int>::max());
    const int m = houses.size();
    const int n = heaters.size();
    // 扫描房子右边的加热器
    for (int i = 0, h = 0; i < m && h < n;) {
      if (houses[i] <= heaters[h]) {
        distance[i] = heaters[h] - houses[i];
        i++;
      } else {
        h++;
      }
    }
    // 扫描房子左边的加热器
    for (int i = m - 1, h = n - 1; i >= 0 && h >= 0;) {
      if (houses[i] >= heaters[h]) {
        distance[i] = min(distance[i], houses[i] - heaters[h]);
        i--;
      } else {
        h--;
      }
    }

    return *max_element(distance.begin(), distance.end());
  }
};
