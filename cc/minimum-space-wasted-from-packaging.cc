// http://leetcode.com/problems/minimum-space-wasted-from-packaging/description/
#include "xxx.hpp"

class Solution {
public:
  int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes) {
    const int mod = 1e9 + 7;
    sort(packages.begin(), packages.end());
    long long sum = accumulate(packages.begin(), packages.end(), 0ll);
    long long ret = numeric_limits<long long>::max();

    for (auto &blst : boxes) {
      sort(blst.begin(), blst.end());
      if (blst.back() >= packages.back()) {
        long long prev = 0;
        long long cur = 0;
        long long total = 0;
        for (auto b : blst) {
          // upper_bound  first one > key
          cur = upper_bound(packages.begin() + prev, packages.end(), b) -
                packages.begin();
          total += b * (cur - prev);
          prev = cur;
        }
        ret = min(ret, total - sum);
      }
    }

    if (ret == numeric_limits<long long>::max()) {
      return -1;
    }

    return ret % mod;
  }
};
