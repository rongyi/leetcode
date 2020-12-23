// http://leetcode.com/problems/stone-game-v/description/
#include "xxx.h"

class Solution {
public:
  int stoneGameV(vector<int> &stoneValue) {
    const int n = stoneValue.size();
    prefix_sum_ = vector<int>(n + 1, 0);
    cache_ = vector<vector<int>>(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
      prefix_sum_[i + 1] = prefix_sum_[i] + stoneValue[i];
    }
    return recur(stoneValue, 0, n - 1);
  }

private:
  // start / end inclusive
  int recur(vector<int> &v, int start, int end) {
    if (start == end) {
      return 0;
    }
    if (cache_[start][end] != -1) {
      return cache_[start][end];
    }
    cache_[start][end] = 0;
    for (int i = start + 1; i <= end; ++i) {
      int l = prefix_sum_[i] - prefix_sum_[start];
      int r = prefix_sum_[end + 1] - prefix_sum_[i];
      if (l < r) {
        cache_[start][end] =
            max(cache_[start][end], recur(v, start, i - 1) + l);
      } else if (l > r) {
        cache_[start][end] = max(cache_[start][end], recur(v, i, end) + r);
      } else {
        cache_[start][end] =
            max(cache_[start][end],
                l + max(recur(v, i, end), recur(v, start, i - 1)));
      }
    }

    return cache_[start][end];
  }

private:
  vector<int> prefix_sum_;
  vector<vector<int>> cache_;
};
