// http://leetcode.com/problems/race-car/description/
#include "xxx.h"

class Solution {
public:
  Solution() { memset(dp_, 0, sizeof(dp_) / sizeof(int)); }
  // https://leetcode.com/problems/race-car/discuss/123834/C%2B%2BJavaPython-DP-solution
  int racecar(int t) {
    if (dp_[t] > 0) {
      return dp_[t];
    }
    int n = floor(log2(t)) + 1;
    if ((1 << n) == t + 1) {
      dp_[t] = n;
    } else {
      dp_[t] = racecar((1 << n) - 1 - t) + n + 1;
      for (int m = 0; m < n - 1; ++m) {
        dp_[t] =
            min(dp_[t], racecar(t - (1 << (n - 1)) + (1 << m)) + n + m + 1);
      }
    }
    return dp_[t];
  }

private:
  int dp_[10001];
};
