// http://leetcode.com/problems/product-of-the-last-k-numbers/description/
#include "xxx.h"

class ProductOfNumbers {
public:
  ProductOfNumbers() { prod_.push_back(1); }

  void add(int num) {
    if (num == 0) {
      prod_ = {1};
    } else {
      prod_.push_back(prod_.back() * num);
    }
  }

  int getProduct(int k) {
    if (k >= prod_.size()) {
      return 0;
    } else {
      return prod_.back() / prod_[prod_.size() - k - 1];
    }
  }

private:
  vector<int> prod_;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
