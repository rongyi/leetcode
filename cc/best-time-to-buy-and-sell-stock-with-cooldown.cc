// http://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
#include "xxx.hpp"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int sz = prices.size();
    if (sz <= 1) {
      return 0;
    }
    //This is a briilian idea, and we can easily write the code with this drawing. However, It took me a long time to figure out what s0, s1, s2 represents. Here are my thoughts, for those who are confused like me. Correct me if I am wrong.
    //s0 means we can buy
    //s1 means we can sell
    //s2 means we take a rest, since we have to take a rest before we buy again, s1 can not go to s0 directly and have to go to s2 first.
    //I guess this will help to understand the code below

    //s0[i] = max(s0[i - 1], s2[i - 1]); // Stay at s0, or rest from s2    //can buy, ie, we have no stock now, and the max profit should be ''last no stock profit'' or ''last rest profit''
    //s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]); // Stay at s1, or buy from s0     //can sell, ie, we now have stock, and the profit should be ''last stock profit'' or ''last no stock but buy this time'' 
    //s2[i] = s1[i - 1] + prices[i]; // Only one way from s1  //we should sell then take a rest
    // profit for last state is cooldown, buy or sell at index i
    // cooldown can stay at cooldown as before or after a sell
    vector<int> cooldown(sz, 0);
    // keep as buy before or from cooldown
    vector<int> buy(sz, 0);
    vector<int> sell(sz, 0);

    buy[0] = -prices[0];
    sell[0] = numeric_limits<int>::min();

    for (int i = 1; i < sz; i++) {
      cooldown[i] = max(cooldown[i - 1], sell[i - 1]);
      // buy one from cooldown
      buy[i] = max(buy[i - 1], cooldown[i - 1] - prices[i]);
      sell[i] = buy[i - 1] + prices[i];
    }

    return max(cooldown[sz - 1], sell[sz - 1]);
  }
};

