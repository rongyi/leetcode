// http://leetcode.com/problems/russian-doll-envelopes/description/
#include "simpleone.h"

class Solution {
public:
  int maxEnvelopes(vector<pair<int, int>> &envelopes) {
    if (envelopes.empty()) {
      return 0;
    }
    sort(envelopes.begin(), envelopes.end());
    vector<int> dp(envelopes.size(), 1);
    for (int i = 0; i < envelopes.size(); i++) {
      // 看前面有多少个比他小的，总是比这哥们多一个
      for (int j = 0; j < i; j++) {
        if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
