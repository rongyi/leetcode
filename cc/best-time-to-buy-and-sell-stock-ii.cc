// http://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int sz = prices.size();
    int sum = 0;
    for (int i = 0; i < sz - 1; i++) {
      if (prices[i + 1] > prices[i]) {
        sum += prices[i + 1] - prices[i];
      }
    }
    return sum;
  }
};
