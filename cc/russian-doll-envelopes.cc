// http://leetcode.com/problems/russian-doll-envelopes/description/
#include "xxx.hpp"

class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    int sz = envelopes.size();
    vector<int> lis;

    // if width is equal, we sort height in desc order
    // why?
    // (1, 1) (1, 2) (1, 3) in this way sort
    // (1, 3) (1, 2) (1, 1) will only have one lis
    // so if the vaule of height is desending
    // we know width is not change, so we only pick one
    sort(envelopes.begin(), envelopes.end(), [](auto &l, auto &r) {
      if (l[0] == r[0]) {
        return l[1] > r[1];
      }
      return l[0] < r[0];
    });

    for (int i = 0; i < sz; i++) {
      auto cur_h = envelopes[i][1];
      auto it = lower_bound(lis.begin(), lis.end(), cur_h);
      if (it == lis.end()) {
        lis.push_back(cur_h);
      } else {
        *it = cur_h;
      }
    }

    return lis.size();
  }
};

class SolutionTLE {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    int sz = envelopes.size();
    // from small envelope to big one
    sort(envelopes.begin(), envelopes.end());
    vector<int> dp(sz, 1);

    for (int i = 0; i < sz; i++) {
      // 看前面有多少个比他小的，总是比这哥们多一个
      for (int j = 0; j < i; j++) {
        if (envelopes[j][0] < envelopes[i][0] &&
            envelopes[j][1] < envelopes[i][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};
