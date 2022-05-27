// https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/
#include "xxx.hpp"

class Solution {
public:
  int minimumLines(vector<vector<int>> &stockPrices) {
    sort(stockPrices.begin(), stockPrices.end());
    int sz = stockPrices.size();
    if (sz == 1) {
      return 0;
    }

    int total_line = 1;
    for (int i = 1; i < stockPrices.size() - 1; ++i) {
      long x1 = stockPrices[i - 1][0];
      long y1 = stockPrices[i - 1][1];

      long x2 = stockPrices[i][0];
      long y2 = stockPrices[i][1];

      long x3 = stockPrices[i + 1][0];
      long y3 = stockPrices[i + 1][1];
      // x/y = m/n ==>  x * n == y * m
      long k1 = (y3 - y2) * (x2 - x1);
      long k2 = (y2 - y1) * (x3 - x2);
      // don't use double!
      if (k1 != k2) {
        total_line += 1;
      }
    }

    return total_line;
  }
};
