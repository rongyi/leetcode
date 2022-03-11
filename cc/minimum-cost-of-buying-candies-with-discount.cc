// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
#include "xxx.hpp"

class Solution {
public:
  int minimumCost(vector<int> &cost) {
    int sz = cost.size();
    int sum = 0;
    // from the big price to lower price and take the higher two
    // and take third for free
    sort(rbegin(cost), rend(cost));

    for (int i = 0; i < sz; ++i) {
      // and take third for free
      if (i % 3 == 2) {
        continue;
      }
      sum += cost[i];
    }

    return sum;
  }
};
