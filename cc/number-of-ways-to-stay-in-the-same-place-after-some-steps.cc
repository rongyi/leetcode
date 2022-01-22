// http://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/
#include "xxx.hpp"

class Solution {
public:
  int numWays(int steps, int arrLen) {
    mod_ = pow(10, 9) + 7;
    vector<vector<int>> cache(steps / 2 + 1, vector<int>(steps + 1, -1));

    return dp(0, steps, arrLen, cache);
  }

private:
  int dp(int pos, int steps, int arr_len, vector<vector<int>> &cache) {
    // 原点，停在那里
    if (pos == 0 && steps == 0) {
      return 1;
    }
    // pos > steps 纵使一直向右也追不上
    if (pos < 0 || pos >= arr_len || steps == 0 || pos > steps) {
      return 0;
    }
    if (cache[pos][steps] != -1) {
      return cache[pos][steps];
    }
    auto r = dp(pos + 1, steps - 1, arr_len, cache) % mod_;
    auto l = dp(pos - 1, steps - 1, arr_len, cache) % mod_;
    auto s = dp(pos, steps - 1, arr_len, cache) % mod_;
    cache[pos][steps] = ((long)r + l + s) % mod_;

    return cache[pos][steps];
  }

private:
  int mod_;
};
