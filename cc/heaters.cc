// http://leetcode.com/problems/heaters/description/
#include "xxx.hpp"

class Solution {
public:
  /*
  Example:    h = house,  * = heater  M = INT_MAX

          h   h   h   h   h   h   h   h   h    houses
          1   2   3   4   5   6   7   8   9    index
          *           *       *                heaters

          0   2   1   0   1   0   -   -   -    (distance to nearest RHS heater)
          0   1   2   0   1   0   1   2   3    (distance to nearest LHS heater)

          0   1   1   0   1   0   1   2   3    (res = minimum of above two)

  Result is maximum value in res, which is 3.
  */

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
