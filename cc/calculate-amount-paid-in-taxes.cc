// https://leetcode.com/problems/calculate-amount-paid-in-taxes/
#include "xxx.hpp"

class Solution {
public:
  double calculateTax(vector<vector<int>> &brackets, int income) {
    double ret = 0.0;
    int prev = 0;
    for (int i = 0; i < brackets.size(); ++i) {
      int incom_range = min(brackets[i][0] - prev, income);
      ret += (incom_range * brackets[i][1]) / 100.0;

      income -= incom_range;
      prev = brackets[i][0];
      if (income <= 0) {
        break;
      }
    }
    return ret;
  }
};
