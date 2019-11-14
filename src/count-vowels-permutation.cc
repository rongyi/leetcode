// http://leetcode.com/problems/count-vowels-permutation/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/count-vowels-permutation/discuss/398222/Detailed-Explanation-using-Graphs-With-Pictures-O(n)
  int countVowelPermutation(int n) {
    const int mod = pow(10, 9) + 7;
    // dp[i][j] 表示总共i条边，然后终点是j节点
    vector<vector<long>> dp(n + 1, vector<long>(5, 0));

    for (int i = 0; i < 5; ++i) {
      dp[1][i] = 1;
    }
    // 0 1 2 3 4
    // a e i o u
    for (int i = 1; i < n; ++i) {
      // a can be reached by e i u
      dp[i + 1][0] = (dp[i][1] + dp[i][2] + dp[i][4]) % mod;
      // e <== a i
      dp[i + 1][1] = (dp[i][0] + dp[i][2]) % mod;
      // i <== e o
      dp[i + 1][2] = (dp[i][1] + dp[i][3]) % mod;
      // o <== i
      dp[i + 1][3] = dp[i][2];
      // u <== i o
      dp[i + 1][4] = (dp[i][2] + dp[i][3]) % mod;
    }

    int ret = 0;

    for (int i = 0; i < 5; ++i) {
      ret = (ret + dp[n][i]) % mod;
    }
    return ret;
  }
};
