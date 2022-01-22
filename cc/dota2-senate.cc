// http://leetcode.com/problems/dota2-senate/description/
#include "xxx.hpp"

class Solution {
public:
  string predictPartyVictory(string senate) {
    queue<int> rq;
    queue<int> dq;
    const int n = senate.size();
    for (int i = 0; i < n; i++) {
      if (senate[i] == 'R') {
        rq.push(i);
      } else {
        dq.push(i);
      }
    }
    while (!rq.empty() && !dq.empty()) {
      auto ridx = rq.front();
      rq.pop();
      auto didx = dq.front();
      dq.pop();
      // 干掉了d，同时把这个R继续入队列放入下一轮
      // 轮与轮的区别就在于加了多少n
      if (ridx < didx) {
        rq.push(ridx + n);
      } else {
        // 干掉了R
        dq.push(didx + n);
      }
    }
    if (rq.size() > dq.size()) {
      return "Radiant";
    }
    return "Dire";
  }
};
