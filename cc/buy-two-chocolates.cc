// https://leetcode.com/problems/buy-two-chocolates/
#include "xxx.hpp"

class Solution {
public:
  int buyChoco(vector<int> &prices, int money) {
    int chok_cnt = 0;
    sort(prices.begin(), prices.end());
    int origin_money = money;
    for (auto &p : prices) {
      // can buy one
      if (p <= money) {
        money -= p;
        chok_cnt += 1;
        if (chok_cnt == 2) {
          return money;
        }
      } else {
        // following chok has higher price that we can not buy
        break;
      }
    }

    return origin_money;
  }
};
