// http://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/description/
#include "xxx.hpp"

class Solution {
public:
  int minSkips(vector<int> &dist, int speed, int hoursBefore) {
    // to avoid floating, we * speed to compare the dist
    // instread of time
    int sz = dist.size();
    sz_ = sz;
    dist_ = dist;
    speed_ = speed;
    dp_ = vector<vector<int>>(sz + 1, vector<int>(sz + 1, -1));

    for (int k = 0; k <= sz; ++k) {
      // arrive before
      if (dfs(sz - 1, k) <= 1ll * hoursBefore * speed) {
        return k;
      }
    }
    return -1;
  }

private:
  int dfs(int i, int k) {
    // no road to pass
    if (i < 0) {
      return 0;
    }
    if (dp_[i][k] != -1) {
      return dp_[i][k];
    }
    // don't skip, make this a standalone chunk, round to the speed
    int ret = (dfs(i - 1, k) + dist_[i] + speed_ - 1) / speed_ * speed_;
    // skip and can skip
    if (k > 0) {
      ret = min(ret, dist_[i] + dfs(i - 1, k - 1));
    }

    return dp_[i][k] = ret;
  }

private:
  int speed_;
  int sz_;
  vector<vector<int>> dp_;
  vector<int> dist_;
};
