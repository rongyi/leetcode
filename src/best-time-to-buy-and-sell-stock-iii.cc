// http://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
#include "xxx.h"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty())
      return 0;
    int ret = 0;
    const int m = prices.size();
    vector<int> first_hand(m, 0);
    vector<int> second_hand(m, 0);

    // first_hand
    int min_buy = prices[0];
    for (int i = 1; i < m; i++) {
      first_hand[i] = std::max(first_hand[i - 1], prices[i] - min_buy);
      min_buy = std::min(min_buy, prices[i]);
    }

    // second_hand
    int max_sell = prices[m - 1];
    for (int i = m - 2; i >= 0; --i) {
      second_hand[i] = std::max(second_hand[i + 1], max_sell - prices[i]);
      max_sell = std::max(max_sell, prices[i]);
    }

    for (int i = 0; i < m; i++) {
      ret = std::max(ret, first_hand[i] + second_hand[i]);
    }

    return ret;
  }
};
