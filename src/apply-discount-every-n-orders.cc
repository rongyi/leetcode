// http://leetcode.com/problems/apply-discount-every-n-orders/description/
#include "xxx.h"

class Cashier {
public:
  Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
      : n_(n), discount_(discount), sn_(1) {
    for (int i = 0; i < products.size(); i++) {
      prices_[products[i]] = prices[i];
    }
  }

  double getBill(vector<int> product, vector<int> amount) {
    double total = 0;
    const int n = product.size();
    for (int i = 0; i < n; i++) {
      total += prices_[product[i]] * amount[i];
    }
    if ((sn_ / n_ >= 1) && (sn_ % n_) == 0) {
      total -= discount_ * total / 100;
    }

    sn_++;

    return total;
  }

private:
  int n_;
  int sn_; // serial number
  int discount_;
  unordered_map<int, int> prices_;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
