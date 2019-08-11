// http://leetcode.com/problems/two-city-scheduling/description/
#include "xxx.h"

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    const int n = costs.size();
    // 靠A近的全部去A呗
    sort(costs.begin(), costs.end(), [](vector<int> &l1, vector<int> &l2) {
      return l1[0] - l1[1] < l2[0] - l2[1];
    });

    int ret = 0;
    for (int i = 0; i < n / 2; i++) {
      ret += costs[i][0] + costs[i + n / 2][1];
    }
    return ret;
  }
};
