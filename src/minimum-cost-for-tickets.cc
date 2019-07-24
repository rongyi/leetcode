// http://leetcode.com/problems/minimum-cost-for-tickets/description/
#include "xxx.h"

class Solution {
public:
  // The higher is the bar, the more you're expected to use dynamic programming
  // (DP) during an interview. This technique requires a lot of practice to
  // grasp; if you've mastered the recursion, DP is the next level.
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    int ret = 0;
    // first: day
    // second: cost
    queue<pair<int, int>> last7;
    queue<pair<int, int>> last30;
    for (auto d : days) {
      while (!last7.empty() && last7.front().first + 7 <= d) {
        last7.pop();
      }
      while (!last30.empty() && last30.front().first + 30 <= d) {
        last30.pop();
      }
      last7.push({d, ret + costs[1]});
      last30.push({d, ret + costs[2]});
      ret = min(ret + costs[0],
                min(last7.front().second, last30.front().second));
    }
    return ret;
  }
};
