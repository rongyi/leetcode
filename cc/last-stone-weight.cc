// http://leetcode.com/problems/last-stone-weight/description/
#include "xxx.hpp"

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> pq;
    for (auto stone: stones) {
      pq.push(stone);
    }

    while (pq.size() > 1) {
      auto l = pq.top();
      pq.pop();
      auto r = pq.top();
      pq.pop();

      if (l != r) {
        pq.push(abs(l - r));
      }
    }

    return pq.empty() ? 0 : pq.top();
  }
};
