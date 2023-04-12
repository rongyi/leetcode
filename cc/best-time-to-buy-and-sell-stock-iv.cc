// http://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
#include "xxx.hpp"

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    int sz = prices.size();
    if (k >= sz / 2) {
      int sum = 0;
      for (int i = 1; i < sz; i++) {
        sum += max(0, prices[i] - prices[i - 1]);
      }
      return sum;
    }
    // Easy to understand explanation for the above solution

    // dp[i][j] = maximum profit from at most i transactions using prices[0..j]

    // A transaction is defined as one buy + sell.

    // Now on day j, we have two options

    // Do nothing (or buy) which doesn't change the acquired profit : dp[i][j] =
    // dp[i][j-1]

    // Sell the stock: In order to sell the stock, you must've bought it on a
    // day t=[0..j-1]. Maximum profit that can be attained is t:0->j-1
    // max(prices[j]-prices[t]+dp[i-1][t-1]) where prices[j]-prices[t] is the
    // profit from buying on day t and selling on day j. dp[i-1][t-1] is the
    // maximum profit that can be made with at most i-1 transactions with prices
    // prices[0..t-1].
    //
    //
    // for i : 1 -> k
    // maxTemp = -prices[0];
    // for j : 1 -> n-1
    // dp[i][j] = max(dp[i][j-1], prices[j]+maxTemp);
    // maxTemp = max(maxTemp, dp[i-1][j-1]-prices[j]);
    // return dp[k][n-1];

    vector<vector<int>> dp(k + 1, vector<int>(sz, 0));

    for (int t = 1; t <= k; t++) {
      int round_max_profit = -prices[0];
      for (int j = 1; j < sz; j++) {
        dp[t][j] = max(dp[t][j - 1], prices[j] + round_max_profit);
        round_max_profit = max(round_max_profit, dp[t - 1][j - 1] - prices[j]);
      }
    }

    return dp[k][sz - 1];
  }
};
