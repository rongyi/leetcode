// http://leetcode.com/problems/numbers-with-same-consecutive-differences/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> numsSameConsecDiff(int N, int K) {
    if (N == 1) {
      return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    }

    vector<int> ret;
    for (int num = 1; num <= 9; num++) {
      dfs(num, N - 1, K, ret);
    }

    return ret;
  }
  void dfs(int acc, int n, int k, vector<int> &ret) {
    if (n == 0) {
      ret.push_back(acc);
      return;
    }
    int last = acc % 10;
    // 往上加
    if (last + k <= 9) {
      dfs(acc * 10 + last + k, n - 1, k, ret);
    }
    // 调过来减, k == 0上面算过了
    if (k != 0 && last - k >= 0) {
      dfs(acc * 10 + last - k, n - 1, k, ret);
    }
  }
};
