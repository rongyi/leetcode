// http://leetcode.com/problems/stone-game-vii/description/
#include "xxx.h"

class Solution {
public:
  int stoneGameVII(vector<int> &stones) {
    const int n = stones.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> prefix(n + 1, 0);
    // prefix of sum till nums[i] ==> prefix[i + 1]
    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = prefix[i] + stones[i];
    }
    // bottom up
    for (int l = 2; l <= n; ++l) {
      for (int i = 0; i <= n - l; ++i) {
        int j = i + l - 1;
        // 1. 取左边, get sum ==> [i + 1, j] ==> prefix[j + 1] - prefix[i + 1]
        // 2. 取右边，get sum ==> [i, j - 1] ==> prefix[j] - prefix[i]
        dp[i][j] = max(prefix[j + 1] - prefix[i + 1] - dp[i + 1][j],
                       prefix[j] - prefix[i] - dp[i][j - 1]);
      }
    }
    return dp[0][n - 1];
  }
};

int main() {
  Solution so;
  vector<int> input{5, 3};
  cout << so.stoneGameVII(input) << endl;
}
