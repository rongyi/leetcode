// http://leetcode.com/problems/positions-of-large-groups/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> ret;
    // 和最后一个不一样即可，用来触发最后一个case
    S.push_back((S[S.size() - 1] - 'a' + 1) % 26 + 'a');
    const int n = S.size();
    int prev = 0;
    char cur = S[0];
    for (int i = 1; i < n; i++) {
      if (S[i] == cur) {
        continue;
      }
      if (i - prev >= 3) {
        ret.push_back({prev, i - 1});
      }
      prev = i;
      cur = S[i];
    }

    return ret;
  }
};
