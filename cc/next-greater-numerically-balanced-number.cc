// https://leetcode.com/problems/next-greater-numerically-balanced-number/
#include "xxx.hpp"

class Solution {
public:
  int nextBeautifulNumber(int n) {
    int sz = to_string(n).size();

    return dfs(n, 0, sz) ?: dfs(0, 0, sz + 1);
  }

private:
  long long dfs(long long num, long long cur, int sz) {
    if (sz == 0) {
      for (int i = 1; i <= 9; ++i) {
        // use partial case
        // i.e. if you use this digit, you must use it all
        if (cnt[i] != i && cnt[i] != 0) {
          return 0;
        }
      }
      return cur > num ? cur : 0;
    }
    long long ret = 0;
    for (int i = 1; i <= 9 && ret == 0; ++i) {
      // this digit can be used, space is sufficient
      if (cnt[i] > 0 && cnt[i] <= sz) {
        --cnt[i];
        ret = dfs(num, cur * 10 + i, sz - 1);
        ++cnt[i];
      }
    }

    return ret;
  }

private:
  int cnt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};
