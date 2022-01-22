// http://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/description/
#include "xxx.hpp"

class Solution {
public:
  int twoEggDrop(int n) {
    vector<int> bests(n + 1);
    // dp[i][j] ==> building have j floors and drop first egg at i level

    bests[0] = 0;
    bests[1] = 1;
    if (n >= 2) {
      bests[2] = 2;
    }

    for (int total_floor = 3; total_floor <= n; ++total_floor) {
      int curBest = n;
      for (int first_drop = 1; first_drop <= total_floor; ++first_drop) {
        // egg breaks at current drop
        int breaks = 1 + first_drop - 1;
        // egg does not break at current drop
        int survive = 1 + bests[total_floor - first_drop];
        // either break or not break, it is a drop that should be counted
        // so we choose the max one as valid drop count

        // https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/discuss/1265931/That-Math-solution-is-too-fancy-to-come-up-with.-Let's-just-try-DP-with-step-by-step-explanations
        curBest = min(curBest, max(breaks, survive));
      }
      bests[total_floor] = curBest;
    }

    return bests[n];
  }
};
