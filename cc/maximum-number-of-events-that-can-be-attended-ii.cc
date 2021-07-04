// http://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/
#include "xxx.h"

class Solution {
public:
  // k ==> maximum meeting you can attend
  int maxValue(vector<vector<int>> &events, int k) {
    const int n = events.size();
    dp_ = vector<vector<int>>(n, vector<int>(k + 1, -1));
    sort(events.begin(), events.end());

    return dfs(events, n, 0, k);
  }

private:
  int dfs(vector<vector<int>> &events, int n, int cur_pos, int k) {
    if (cur_pos >= n || k == 0) {
      return 0;
    }
    if (dp_[cur_pos][k] != -1) {
      return dp_[cur_pos][k];
    }
    // int nex_valid = 0;
    // for (; nex_valid < n; ++nex_valid) {
    //   // 首尾不相连
    //   if (events[nex_valid][0] > events[cur_pos][1]) {
    //     break;
    //   }
    // }

    // binary search加速
    // 找到下一个首尾不相接的
    auto nex_valid =
        upper_bound(begin(events), end(events), events[cur_pos][1],
                    [](int t, const vector<int> &v) { return v[0] > t; }) -
        begin(events);

    return dp_[cur_pos][k] =
               max(dfs(events, n, cur_pos + 1, k),
                   events[cur_pos][2] + dfs(events, n, nex_valid, k - 1));
  }

private:
  vector<vector<int>> dp_;
};
