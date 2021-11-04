// http://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/
#include "xxx.h"

class Solution {
public:
  int colorTheGrid(int m, int n) {
    m_ = m;
    n_ = n;
    return dp(0, 0);
  }

private:
  // 3 color fits in 2 bit, and total 5 rows , so 10 bits is enough
  int getColor(int mask, int pos) { return (mask >> (2 * pos)) & 3; }
  int setColor(int mask, int pos, int color) {
    return mask | (color << (2 * pos));
  }
  int dp(int c, int prev_col_mask) {
    // found a valid way
    if (c == n_) {
      return 1;
    }
    if (dp_[c][prev_col_mask]) {
      return dp_[c][prev_col_mask];
    }
    int ret = 0;
    for (auto nei : neighbors(prev_col_mask)) {
      ret = (ret + dp(c + 1, nei)) % mod_;
    }
    return dp_[c][prev_col_mask] = ret;
  }

  // give prev col mask , generate all *valid* color columen for current col
  vector<int> neighbors(int prev_col_mask) {
    if (!nei_memo_[prev_col_mask].empty()) {
      return nei_memo_[prev_col_mask];
    }
    dfs(0, prev_col_mask, 0, nei_memo_[prev_col_mask]);
    return nei_memo_[prev_col_mask];
  }
  void dfs(int r, int prev_col_mask, int cur_col_mask, vector<int> &out) {
    if (r == m_) {
      out.push_back(cur_col_mask);
      return;
    }
    for (int i = 1; i <= 3; ++i) {
      if (getColor(prev_col_mask, r) != i &&
          (r == 0 || (getColor(cur_col_mask, r - 1) != i))) {
        dfs(r + 1, prev_col_mask, setColor(cur_col_mask, r, i), out);
      }
    }
  }

private:
  static constexpr int mod_ = 1e9 + 7;
  int m_;
  int n_;
  // dp[i][j] : i col, j mask
  int dp_[1000][1024] = {};
  vector<int> nei_memo_[1024] = {};
};
