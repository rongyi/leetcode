// http://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/description/
#include "xxx.h"

class Solution {
public:
  int getMaximumConsecutive(vector<int> &coins) {
    sort(coins.begin(), coins.end());
    // 出现gap的原因即是当前到达的最大值 < 下一个数字
    int current_reach = 0;
    for (int i = 0; i < coins.size() && coins[i] <= current_reach + 1; ++i) {
      current_reach += coins[i];
    }

    return current_reach + 1;
  }
};
