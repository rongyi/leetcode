// http://leetcode.com/problems/stone-game-vi/description/
#include "xxx.hpp"

class Solution {
public:
  int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {
    const int n = aliceValues.size();
    vector<array<int, 3>> sums;
    for (int i = 0; i < n; i++) {
      sums.push_back(
          {aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]});
    }
    sort(sums.rbegin(), sums.rend());

    int alice = 0;
    int bob = 0;
    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        bob += sums[i][2];
      } else {
        // alice先来，偶数
        alice += sums[i][1];
      }
    }

    if (alice == bob) {
      return 0;
    } else if (alice > bob) {
      return 1;
    }
    return -1;
  }
};
