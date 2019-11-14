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
      // 'a' can be reached by e i u
      dp[i + 1][0] = (dp[i][1] + dp[i][2] + dp[i][4]) % mod;
    }
  }
};
