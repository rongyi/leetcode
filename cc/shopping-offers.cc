// http://leetcode.com/problems/shopping-offers/description/
#include "xxx.h"

class Solution {
public:
  // 就是把所有的可能都尝试了，找代价最小的
  int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                     vector<int> &needs) {
    // 本身分开买所需要的最大值
    int ret = inner_product(price.begin(), price.end(), needs.begin(), 0);
    for (const auto &offer : special) {
      vector<int> r = can(needs, offer);
      if (r.empty()) {
        continue;
      }
      ret = min(ret, offer.back() + shoppingOffers(price, special, r));
    }
    return ret;
  }
  vector<int> can(const vector<int> &needs, const vector<int> &offer) {
    // remain list
    vector<int> r(needs.size(), 0);
    for (int i = 0, n = needs.size(); i < n; ++i) {
      // 只能买exactly，所以只要有多的情况就不能买了，因为消费不掉
      if (offer[i] > needs[i]) {
        return vector<int>{};
      }
      r[i] = needs[i] - offer[i];
    }
    return r;
  }
};
