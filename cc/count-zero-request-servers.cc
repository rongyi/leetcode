// https://leetcode.com/problems/count-zero-request-servers/
#include "xxx.hpp"

class Solution {
public:
  vector<int> countServers(int n, vector<vector<int>> &logs, int x,
                           vector<int> &qs) {
    vector<int> ret(qs.size(), 0);
    vector<int> ids(qs.size(), 0);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) { return qs[i] < qs[j]; });

    // for accumulation
    vector<int> cnt(n + 1, 0);
    // sort logs by time, from small to big
    // [{server, time}]
    sort(logs.begin(), logs.end(),
         [&](auto &l, auto &r) { return l[1] < r[1]; });
    int i = 0;
    int j = 0;
    int acc = 0;
    for (auto &id : ids) {
      for (; j < logs.size() && logs[j][1] <= qs[id]; ++j) {
        // count only once, so we check the 1 case;
        acc += (++cnt[logs[j][0]] == 1);
      }
      for (; i < logs.size() && logs[i][1] < qs[id] - x; ++i) {
        acc -= (--cnt[logs[i][0]] == 0);
      }

      ret[id] = n - acc;
    }

    return ret;
  }
};
