// http://leetcode.com/problems/count-all-possible-routes/description/
#include "xxx.h"

class Solution {
public:
  int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
    const int n = locations.size();
    // 表示到节点 i 时还有的fuel
    vector<vector<int>> dp(n, vector<int>(201, -1));
    return recur(locations, start, finish, fuel, dp);
  }

private:
  int recur(vector<int> &locations, int start, int finish, int fuel,
            vector<vector<int>> &dp) {
    if (dp[start][fuel] != -1) {
      return dp[start][fuel];
    }
    dp[start][fuel] = 0;
    if (start == finish) {
      dp[start][fuel] += 1;
    }
    for (int i = 0; i < locations.size(); ++i) {
      if (i == start || fuel < abs(locations[start] - locations[i])) {
        continue;
      }
      dp[start][fuel] =
          (dp[start][fuel] + recur(locations, i, finish,
                                   fuel - abs(locations[start] - locations[i]),
                                   dp)) %
          1000000007;
    }

    return dp[start][fuel];
  }
};
