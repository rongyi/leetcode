// http://leetcode.com/problems/stone-game-v/description/
#include "xxx.hpp"

class Solution {
public:
  int stoneGameV(vector<int> &stoneValue) {
    const int n = stoneValue.size();
    prefix_sum_ = vector<int>(n + 1, 0);
    cache_ = vector<vector<int>>(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
      prefix_sum_[i + 1] = prefix_sum_[i] + stoneValue[i];
    }
    return recur(0, n - 1);
  }

private:
  // start / end inclusive
  int recur(int start, int end) {
    if (start == end) {
      return 0;
    }
    if (cache_[start][end] != -1) {
      return cache_[start][end];
    }
    cache_[start][end] = 0;
    // 这里从prefixsum的角度去看要好些
    for (int i = start + 1; i <= end; ++i) {
      int l = prefix_sum_[i] - prefix_sum_[start];
      int r = prefix_sum_[end + 1] - prefix_sum_[i];
      if (l < r) {
        // 右边被扔掉
        cache_[start][end] = max(cache_[start][end], recur(start, i - 1) + l);
      } else if (l > r) {
        // 左边被扔掉
        cache_[start][end] = max(cache_[start][end], recur(i, end) + r);
      } else {
        // 这两边都计算下去看谁最高
        cache_[start][end] = max(cache_[start][end],
                                 l + max(recur(i, end), recur(start, i - 1)));
      }
    }

    return cache_[start][end];
  }

private:
  vector<int> prefix_sum_;
  vector<vector<int>> cache_;
};
