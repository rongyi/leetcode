// https://leetcode.com/problems/maximum-good-people-based-on-statements/
#include "xxx.hpp"

class Solution {
public:
  // ignore bad person
  int maximumGood(vector<vector<int>> &statements) {
    int n = statements.size();
    int ret = 0;
    auto valid = [&](int mask) {
      for (int i = 0; i < n; ++i) {
        // person i is good?
        if ((mask >> i) & 1) {
          for (int j = 0; j < n; ++j) {
            int good = (mask >> j) & 1;
            // what good i says to j is contradict to current status
            if ((statements[i][j] == 0 && good) ||
                (statements[i][j] == 1 && !good)) {
              return false;
            }
          }
        }
      }
      return true;
    };
    for (int m = 1; m < (1 << n); ++m) {
      if (valid(m)) {
        ret = max(ret, __builtin_popcount(m));
      }
    }

    return ret;
  }
};
