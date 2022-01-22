// http://leetcode.com/problems/best-team-with-no-conflicts/description/
#include "xxx.hpp"

class Solution {
public:
  // 要求是选手年龄大实例也要强，如果选了一个岁数小的，那么他的实例也不能超过岁数大的
  // 岁数大能力又强 -> 选
  int bestTeamScore(vector<int> &scores, vector<int> &ages) {
    const int n = ages.size();
    // 按年龄排序，岁数大的在前
    vector<pair<int, int>> ps;
    for (int i = 0; i < n; ++i) {
      ps.push_back({ages[i], scores[i]});
    }
    sort(ps.begin(), ps.end(), greater<>());
    // dp[i] => 到i能取到的最高分
    // dp[i] stores the maximum score that can be obtained when i-th player is
    // included and all other players are between indices 0 and i-1.
    vector<int> dp(n);
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      // 至少可以自成一队，先选自己
      dp[i] = ps[i].second;
      // 前面大哥能力不如自己选上了，自己就不能上
      // 前面的大哥能力比自己强可以一起组队
      for (int j = 0; j < i; ++j) {
        // 看看能力
        if (ps[j].second >= ps[i].second) {
          // dp[j]是到j能取的最大值
          dp[i] = max(dp[i], dp[j] + ps[i].second);
        }
      }

      ret = max(ret, dp[i]);
    }

    return ret;
  }
};
