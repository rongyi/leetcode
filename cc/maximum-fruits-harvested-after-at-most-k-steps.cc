// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/
#include "xxx.hpp"

class Solution {
public:
  int maxTotalFruits(vector<vector<int>> &fruits, int sp, int k) {
    int n = 2e5 + 1;
    vector<int> v(n, 0);
    for (auto &f : fruits) {
      v[f[0]] = f[1];
    }
    long long ret = 0;
    // collect to right direction
    vector<long long> left(n, 0);
    // collect to left direction
    vector<long long> right(n, 0);
    left[sp] = v[sp];
    right[sp] = v[sp];

    for (int i = sp - 1; i >= 0; i--) {
      left[i] = left[i + 1] + v[i];
    }
    for (int i = sp + 1; i < n; ++i) {
      right[i] = right[i - 1] + v[i];
    }

    // walking left i times and i times backwards
    // and see the right can get
    for (int i = 0; i <= min(k, sp); ++i) {
      int r = min(k - 2 * i, n - 1 - sp); // n - (sp + 1) is the left step
                                          // total, we can not over this count
      if (r >= 0 && sp + r < n) {
        ret = max(ret, left[sp - i] + right[sp + r] - v[sp]);
      }
    }

    // walking right i times and i times backwards
    // and see the left can get
    for (int i = 0; i <= min(k, n - 1 - sp); ++i) {
      int l = min(k - 2 * i, sp);
      if (l >= 0 && sp - l >= 0) {
        ret = max(ret, left[sp - l] + right[sp + i] - v[sp]);
      }
    }

    return (int)ret;
  }
};
