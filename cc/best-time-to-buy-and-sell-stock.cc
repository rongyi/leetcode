// http://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include "xxx.h"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    const int n = prices.size();
    int ret = 0;
    int cur_max = 0;
    for (int i = n - 2; i >= 0; --i) {
      cur_max = max(cur_max, prices[i + 1]);
      // 比当前节点大，说明从这点买进可以在后续某个时间点卖出
      if (cur_max > prices[i]) {
        ret = max(ret, cur_max - prices[i]);
      }
    }

    return ret;
  }
};
