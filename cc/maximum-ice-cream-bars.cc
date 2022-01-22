// http://leetcode.com/problems/maximum-ice-cream-bars/description/
#include "xxx.hpp"

class Solution {
public:
  int maxIceCream(vector<int> &costs, int coins) {
    // pick low price first
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> pq(costs.begin(),
                                                      costs.end());
    while (!pq.empty()) {
      auto cur_price = pq.top();
      pq.pop();
      if (cur_price > coins) {
        break;
      }
      count++;
      coins -= cur_price;
    }

    return count;
  }
};
