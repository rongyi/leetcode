// http://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/
#include "xxx.h"

class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    vector<int> ret;
    for (int i = 0; i < prices.size(); ++i) {
      auto cur = prices[i];
      for (int j = i + 1; j < prices.size(); ++j) {
        if (prices[j] <= cur) {
          cur -= prices[j];
          break;
        }
      }
      ret.push_back(cur);
    }
    return ret;
  }
};
