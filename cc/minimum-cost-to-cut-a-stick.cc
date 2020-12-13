// http://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
#include "xxx.h"

class Solution {
public:
  int minCost(int n, vector<int> &cuts) {
    // 仅仅是为了好算长度
    // https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/901997/C%2B%2B-Dynamic-Programming-or-INTUITIVE-or-GIVE-IT-A-READ-or
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    const int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, numeric_limits<int>::max()));

    return dfs(dp, cuts, 0, m - 1);
  }

private:
  int dfs(vector<vector<int>> &dp, vector<int> &cuts, int i, int j) {
    // j i 现在是点，连为一个stick没有耗费
    if (j - i <= 1) {
      return 0;
    }
    if (dp[i][j] == numeric_limits<int>::max()) {
      for (int k = i + 1; k < j; ++k) {
        dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dfs(dp, cuts, i, k) +
                                     dfs(dp, cuts, k, j));
      }
    }

    return dp[i][j];
  }
};
