// http://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
#include "xxx.h"

class Solution {
public:
  // 系列总结:
  // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems
  int maxProfit(vector<int> &prices, int fee) {
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108867/C%2B%2B-concise-solution-O(n)-time-O(1)-space
    // s0 = profit having no stock
    // s1 = profit having 1 stock
    // update s0 by selling the stock from s1, so s0 = max(s0, s1+p);
    // update s1 by buying the stock from s0, so s1 = max(s1, s0-p-fee);

    int s0 = 0;
    int s1 = numeric_limits<int>::min();
    for (auto p : prices) {
      int tmp = s0;
      s0 = max(s0, s1 + p);
      s1 = max(s1, tmp - p - fee);
    }

    return s0;
  }
};
