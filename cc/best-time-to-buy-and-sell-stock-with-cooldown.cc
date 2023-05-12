// http://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/761981/python-go-java-js-c-o-n-by-dp-and-state-machine-w-visualization/?orderBy=most_votes
  int maxProfit(vector<int> &prices) {
    int sz = prices.size();
    if (sz <= 1) {
      return 0;
    }
    // three state: cooldown, hold, sell
    // to indicate the maxProfit when ending state is: cooldown, or holding
    // or just selling
    int cooldown = 0;
    int hold = numeric_limits<int>::min();
    int sell = 0;

    for (auto p : prices) {
      int prevHold = hold;
      int prevSell = sell;
      int prevCooldown = cooldown;

      // stay as cooldown or come from a prev selling
      cooldown = max(prevCooldown, prevSell);
      // only one state
      sell = prevHold + p;
      hold = max(prevHold, prevCooldown - p);
    }

    return max(cooldown, sell);
  }
};

