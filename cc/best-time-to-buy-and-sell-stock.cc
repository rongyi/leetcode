// http://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include "xxx.hpp"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int sz = prices.size();
    int profit = 0;
    int sell = prices[sz - 1];
    for (int i = sz - 2; i >= 0; i--) {
      profit = max(profit, sell - prices[i]);
      // for next round
      sell = max(sell, prices[i]);
    }

    return max(0, profit);
  }
};
