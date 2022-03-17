// https://leetcode.com/problems/minimum-cost-to-set-cooking-time/
#include "xxx.hpp"

class Solution {
public:
  // what a fucking problem
  int minCostSetTime(int startAt, int moveCost, int pushCost,
                     int targetSeconds) {
    auto pmc = [&](int curpos, int mint, int sec) {
      if (min(mint, sec) < 0 || max(mint, sec) > 99) {
        return numeric_limits<int>::max();
      }
      int cnt = 0;
      string display = to_string(mint * 100 + sec);
      for (auto c : display) {
        // press one button
        cnt += pushCost;
        if ((c - '0') != curpos) {
          cnt += moveCost;
          curpos = (c - '0');
        }
      }
      return cnt;
    };
    int mint = targetSeconds / 60;
    int sec = targetSeconds % 60;

    return min(pmc(startAt, mint, sec), pmc(startAt, mint - 1, sec + 60));
  }
};
