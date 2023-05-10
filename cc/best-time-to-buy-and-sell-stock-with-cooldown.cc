// http://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
#include "xxx.hpp"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int sz = prices.size();
    if (sz <= 1) {
      return 0;
    }
    // profit for last state is cooldown, buy or sell at index i
    vector<int> cooldown(sz, 0);
    vector<int> buy(sz, 0);
    vector<int> sell(sz, 0);

    buy[0] = -prices[0];
    sell[0] = numeric_limits<int>::min();

    for (int i = 1; i < sz; i++) {
      cooldown[i] = max(cooldown[i - 1], sell[i - 1]);
      // buy one from cooldown
      buy[i] = max(buy[i - 1], cooldown[i - 1] - prices[i]);
      sell[i] = buy[i - 1] + prices[i];
    }

    return max(cooldown[sz - 1], sell[sz - 1]);
  }
};

