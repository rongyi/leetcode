// http://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/description/
#include "xxx.hpp"

class Solution {
public:
  // 喷的很
  int minOperationsMaxProfit(vector<int> &customers, int boardingCost,
                             int runningCost) {
    int wait = 0;
    int prof = 0;
    int max_prof = 0;
    int max_i = -1;
    for (int i = 0; i < customers.size() || wait > 0; ++i) {
      if (i < customers.size()) {
        wait += customers[i];
      }
      prof += min(4, wait) * boardingCost - runningCost;
      wait -= min(4, wait);
      if (max_prof < prof) {
        max_prof = prof;
        max_i = i + 1;
      }
    }

    return max_i;
  }
};
