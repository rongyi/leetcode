// http://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/description/
#include "xxx.hpp"

class Solution {
public:
  int rearrangeSticks(int n, int k) {
    if (k == n) {
      return 1;
    }
    // https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/discuss/1214875/Almost-AC-vs.-4-ms.
    if (k > 0 && n > k && !dp_[n][k]) {
      dp_[n][k] = ((long)(n - 1) * rearrangeSticks(n - 1, k) +
                   rearrangeSticks(n - 1, k - 1) + dp_[n][k]) %
                  mod_;
    }

    return dp_[n][k];
  }

private:
  int dp_[10001][1001] = {};
  int mod_ = 1e9 + 7;
};
