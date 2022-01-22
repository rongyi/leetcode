// http://leetcode.com/problems/profitable-schemes/description/
#include "xxx.hpp"

class Solution {
public:
  int profitableSchemes(int G, int P, vector<int> &group, vector<int> &profit) {
    // dp[i][j] j个人产生i个profit
    vector<vector<int>> dp(P + 1, vector<int>(G + 1, 0));
    dp[0][0] = 1;
    int ret = 0;
    int mod = pow(10, 9) + 7;

    for (int k = 0; k < group.size(); k++) {
      int g = group[k];
      int p = profit[k];
      for (int i = P; i >= 0; i--) {
        for (int j = G - g; j>= 0; j--) {
          dp[min(i + p, P)][j + g] = (dp[min(i + p, P)][j + g] + dp[i][j]) % mod;
        }
      }
    }
    for (auto x : dp[P]) {
      ret = (ret + x) % mod;
    }
    return ret;
  }
};
