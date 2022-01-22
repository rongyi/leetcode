// http://leetcode.com/problems/tallest-billboard/description/
#include "xxx.hpp"

class Solution {
public:
  int tallestBillboard(vector<int> &rods) {
    // key 表示左腿减右腿的差
    // value 表示左腿能要多高？
    unordered_map<int, int> dp;
    // 两边都是0的情况，高度也是0
    dp[0] = 0;

    for (auto leg : rods) {
      unordered_map<int, int> tmp;
      tmp.insert(dp.begin(), dp.end());

      for (auto &kv : dp) {
        int cur_diff = kv.first;
        // 当前这个腿焊在左边, 那么差会变大 leg
        tmp[cur_diff + leg] = max(tmp[cur_diff + leg], dp[cur_diff] + leg);
        // 当前这个腿焊在右边差会变小
        tmp[cur_diff - leg] = max(tmp[cur_diff - leg], dp[cur_diff]);
      }
      dp.clear();
      dp.insert(tmp.begin(), tmp.end());
    }

    return dp[0];
  }
};
