// https://leetcode.com/problems/stock-price-fluctuation/
#include "xxx.h"

class StockPrice {
public:
  StockPrice() {}

  void update(int timestamp, int price) {
    if (candle_.count(timestamp)) {
      auto old_price = candle_[timestamp];
      // price need sorted
      price_count_[old_price]--;
      // delete this price in cache
      if (price_count_[old_price] == 0) {
        price_count_.erase(old_price);
      }
    }

    candle_[timestamp] = price;
    price_count_[price]++;
  }

  int current() {
    return prev(candle_.end())->second;
  }

  int maximum() {
    // the one with count > 0
    return prev(price_count_.end())->first;
  }

  int minimum() {
    return price_count_.begin()->first;
  }
private:
  map<int, int> candle_;
  map<int, int> price_count_;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
