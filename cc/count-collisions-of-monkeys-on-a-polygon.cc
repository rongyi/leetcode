// https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/
#include "xxx.hpp"

class Solution {
  using ll = long long;

public:
  int monkeyMove(int n) {
    int t = modpower(2, n) - 2;
    if (t < 0) {
      return mod_ + t;
    }
    return t;
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
