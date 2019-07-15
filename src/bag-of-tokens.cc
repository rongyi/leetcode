// http://leetcode.com/problems/bag-of-tokens/description/
#include "xxx.h"

class Solution {
public:
  int bagOfTokensScore(vector<int> &tokens, int P) {
    if (tokens.empty()) {
      return 0;
    }
    // P当成血
    // points 鸡腿
    int points = 0;

    sort(tokens.begin(), tokens.end());
    // 啥都不能干
    if (P < tokens[0]) {
      return 0;
    }
    int l = 0;
    int r = tokens.size() - 1;
    while (l <= r) {
      while (P < tokens[l] && points > 0) {
        points--;
        P += tokens[r];
        r--;
      }
      if (P < tokens[l]) {
        return points;
      }
      P -= tokens[l];
      l++;
      points++;
    }

    return points;
  }
};
