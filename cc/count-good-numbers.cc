// https://leetcode.com/problems/count-good-numbers/
#include "xxx.h"

using ll = long long;
class Solution {
public:
  // bad question?
  int countGoodNumbers(long long n) {
    // 2 3 5 7
    ll count_of_4s = n / 2;
    // 2 4 6 8 0
    ll count_of_5s = n - count_of_4s;
    ll ret = ((modpower(4ll, count_of_4s) % mod_ * modpower(5ll, count_of_5s) %
               mod_) %
              mod_);

    return ret;
  }

private:
  ll modpower(ll x, ll y) {
    ll ret = 1;
    // format x
    x %= mod_;
    while (y > 0) {
      if (y & 1) {
        ret = (ret * x) % mod_;
      }
      y >>= 1;
      x = (x * x) % mod_;
    }

    return ret;
  }

private:
  static constexpr int mod_ = 1e9 + 7;
};
