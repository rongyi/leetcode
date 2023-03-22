// http://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
#include "xxx.hpp"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int sz = prices.size();
    vector<int> tx1(sz, 0);
    vector<int> tx2(sz, 0);

    int buy = prices[0];
    for (int i = 1; i < sz; i++) {
      int profit = prices[i] - buy;
      tx1[i] = max(tx1[i - 1], profit);
      buy = min(buy, prices[i]);
    }

    int sell = prices[sz - 1];
    for (int i = sz - 2; i >= 0; i--) {
      int profit = sell - prices[i];
      tx2[i] = max(tx2[i + 1], profit);
      sell = max(sell, prices[i]);
    }
    int ret = 0;
    for (int i = 0; i < sz; i++) {
      ret = max(ret, tx1[i] + tx2[i]);
    }

    return ret;
  }
};
