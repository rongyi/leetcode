// https://leetcode.com/problems/maximize-win-from-two-segments/
#include "xxx.hpp"

class Solution {
public:
  int maximizeWin(vector<int> &prizePositions, int k) {
    // don't group, this is a sliding window
    int sz = prizePositions.size();
    // dp[i + 1] end with index i, get the maximize cover, put
    // value to i + 1
    vector<int> dp(sz + 1, 0);

    int ret = 0;
    for (int i = 0, j = 0; i < sz; i++) {
      while (prizePositions[j] < prizePositions[i] - k) {
        j++;
      }
      dp[i + 1] = max(dp[i], i - j + 1);
      ret = max(ret, dp[j] + (i - j + 1));
    }
    return ret;
  }
};
