// http://leetcode.com/problems/number-of-orders-in-the-backlog/description/
#include "xxx.h"

class Solution {
public:
  // 喷的很惨
  int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
    // 如果是卖单，就去看买单队列，选最高价
    // 如果是买单，就去看卖单队列，选最低价
    // 所以： 卖单队列 小顶堆 方便买家选最便宜的
    //       买单队列 大顶堆 方便卖家选最贵的
    // C++默认大顶堆，这里放在sell的要取反达到小顶堆的效果
    priority_queue<array<int, 2>> buy;
    priority_queue<array<int, 2>> sell;

    long ret = 0;

    // price amount ordertype
    // 1 ==> sell order
    // 2 ==> buy order
    for (auto &o : orders) {
      ret += o[1];
      if (o[2]) {
        sell.push({-o[0], o[1]});
      } else {
        buy.push({o[0], o[1]});
      }
      while (!sell.empty() && !buy.empty() && -sell.top()[0] <= buy.top()[0]) {
        auto [sell_p, sell_a] = sell.top();
        sell.pop();
        auto [buy_p, buy_a] = buy.top();
        buy.pop();
        auto cut = min(sell_a, buy_a);
        ret -= 2 * cut;

        if (sell_a > cut) {
          sell.push({sell_p, sell_a - cut});
        }
        if (buy_a > cut) {
          buy.push({buy_p, buy_a - cut});
        }
      }
    }

    const int mod = 1e9 + 7;
    return ret % mod;
  }
};
