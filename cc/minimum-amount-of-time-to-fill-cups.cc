// https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/
#include "xxx.hpp"

class Solution {
public:
  int fillCups(vector<int> &amount) {
    priority_queue<int> pq;
    for (auto &w : amount) {
      // the give us empty count!
      if (w > 0) {
        pq.push(w);
      }
    }
    int ret = 0;
    while (!pq.empty()) {
      if (pq.size() == 1) {
        ret += pq.top();
        pq.pop();
      } else {
        auto w1 = pq.top();
        pq.pop();
        auto w2 = pq.top();
        pq.pop();
        ret++;
        w1--;
        w2--;
        if (w1 > 0) {
          pq.push(w1);
        }
        if (w2 > 0) {
          pq.push(w2);
        }
      }
    }

    return ret;
  }
};
