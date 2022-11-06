// https://leetcode.com/problems/minimum-money-required-before-transactions/
#include "xxx.hpp"

class Solution {
public:
  long long minimumMoney(vector<vector<int>> &transactions) {
    long long spend = 0;
    long long last_profit = 0;
    long long init_cost = 0;

    for (auto &t : transactions) {
      if (t[0] > t[1]) {
        // we lost money to do this transaction
        // so we add what we lost
        spend += (t[0] - t[1]);
        // the last profit can not be add to spend
        // so we track the most lost
        last_profit = max(last_profit, (long long)t[1]);
      } else {
        // init start, we need at least cost
        init_cost = max(init_cost, (long long)t[0]);
      }
    }

    return spend + max(last_profit, init_cost);
  }
};
