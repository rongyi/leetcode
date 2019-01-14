// http://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
#include "xxx.h"

class Solution {
public:
  // 递归超时了 :(
  int maxProfitTLEVersion(vector<int> &prices) {
    int ret = 0;
    doProfit(prices, 0, ret, 0);

    return ret;
  }
  // 我们可以昨天买入，今日卖出，若明日价更高的话，还可以今日买入，明日再抛出
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }
    int ret = 0;
    for (int i = 0; i < prices.size() - 1; i++) {
      if (prices[i] < prices[i + 1]) {
        ret += prices[i + 1] - prices[i];
      }
    }

    return ret;
  }

private:
  void doProfit(vector<int> &prices, int cur_idx, int &ret, int cur_profit) {
    if (cur_idx >= prices.size()) {
      ret = max(ret, cur_profit);
      return;
    }

    // see if we can profit this round
    for (int i = cur_idx + 1; i < prices.size(); ++i) {
      // can profit, we sellit
      if (prices[i] > prices[cur_idx]) {
        doProfit(prices, i + 1, ret,
                 cur_profit + (prices[i] - prices[cur_idx]));
      }
    }
    // continue to next
    doProfit(prices, cur_idx + 1, ret, cur_profit);
  }
};
int main() {
  Solution so;
  vector<int> input{7, 1, 5, 3, 6, 4};
  auto ret = so.maxProfitTLEVersion(input);
  cout << ret << endl;
}
