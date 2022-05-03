// https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/
#include "xxx.hpp"

class Solution {
public:
  long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    long long all_pen = total / cost1;

    long long ret = 0;
    for (int i = 0; i <= all_pen; ++i) {
      long long left_money = total - cost1 * i;
      long long pencil_max = left_money / cost2;

      ret += pencil_max + 1;
    }

    return ret;
  }
};
