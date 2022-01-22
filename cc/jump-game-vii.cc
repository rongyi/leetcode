// http://leetcode.com/problems/jump-game-vii/description/
#include "xxx.hpp"

class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int sz = s.size();
    if (s[sz - 1] != '0') {
      return false;
    }

    queue<int> q;
    q.push(0);
    // the key point is here: start with max reach for next round
    int max_reach = 0;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (cur == sz - 1) {
        return true;
      }
      for (int i = max(cur + minJump, max_reach);
           i <= min(sz - 1, cur + maxJump); ++i) {
        if (s[i] == '0') {
          q.push(i);
        }
      }
      max_reach = min(sz - 1, cur + maxJump + 1);
    }

    return false;
  }
};
