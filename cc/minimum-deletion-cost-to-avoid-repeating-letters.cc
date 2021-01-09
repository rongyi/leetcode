// http://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/description/
#include "xxx.h"

class Solution {
public:
  int minCost(string s, vector<int> &cost) {
    int max_cost = cost[0];
    int ret = cost[0];
    for (int i = 1; i < s.size(); ++i) {
      // 清算前面的
      if (s[i] != s[i - 1]) {
        ret -= max_cost;
        max_cost = 0;
      }
      // 如果一样的话
      ret += cost[i];
      max_cost = max(max_cost, cost[i]);
    }

    return ret - max_cost;
  }
};
