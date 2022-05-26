// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
#include "xxx.hpp"

class Solution {
public:
  int maximumBags(vector<int> &capacity, vector<int> &rocks,
      int additionalRocks) {
    int full = 0;
    int sz = capacity.size();
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < sz; ++i) {
      auto can_fill = capacity[i] - rocks[i];
      if (can_fill == 0) {
        full += 1;
      } else {
        q.push(can_fill);
      }
    }

    while (!q.empty()) {
      if (additionalRocks >= q.top()) {
        additionalRocks -= q.top();
        q.pop();

        full++;
      } else {
        break;
      }
    }


    return full;
  }
};
