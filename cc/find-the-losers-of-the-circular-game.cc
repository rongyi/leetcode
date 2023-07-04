// https://leetcode.com/problems/find-the-losers-of-the-circular-game/
#include "xxx.hpp"

class Solution {
public:
  vector<int> circularGameLosers(int n, int k) {
    vector<int> have_ball(n, false);
    have_ball[0] = true;
    int round = 1;
    int current = 0;

    while (true) {
      int next = (current + round * k % n) % n;
      if (have_ball[next]) {
        break;
      }

      have_ball[next] = true;
      current = next;
      round++;
    }

    vector<int> ret;
    for (int i = 0; i < n; i++) {
      if (!have_ball[i]) {
        ret.push_back(i + 1);
      }
    }
    return ret;
  }
};
