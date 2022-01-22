// http://leetcode.com/problems/online-stock-span/description/
#include "xxx.hpp"

class StockSpanner {
public:
  StockSpanner() {}

  int next(int price) {
    // including itself
    int ret = 1;
    while (!stk_.empty() && stk_.top().first <= price) {
      ret += stk_.top().second;
      stk_.pop();
    }

    stk_.push({price, ret});

    return ret;
  }

private:
  // pair ==> 当前的数字以及比他小包含他自己的个数
  stack<pair<int, int>> stk_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
