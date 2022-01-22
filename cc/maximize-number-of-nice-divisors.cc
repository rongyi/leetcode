// http://leetcode.com/problems/maximize-number-of-nice-divisors/description/
#include "xxx.hpp"

class Solution {
  using ll = long long;

public:
  // 喷的很惨的一题
  // 其实就是和固定，求积的最大值
  int maxNiceDivisors(int x) {
    if (x == 1) {
      return 1;
    }
    ll b = x / 3;
    ll a = x - b * 3;
    ll mod = 1e9 + 7;
    ll two_count = 0;
    // 1, 3 ==> 2 2
    if (a == 1) {
      two_count = 2;
      b--;
    } else if (a == 2) {
      two_count = 1;
    }

    return pow_mod(2, two_count, mod) * pow_mod(3, b, mod) % mod;
  }

private:
  ll pow_mod(ll x, ll y, int mod) {
    ll a = x % mod;
    ll ret = 1;
    while (y) {
      if (y & 1) {
        ret = (ret * a) % mod;
      }
      a = (a * a) % mod;

      y >>= 1;
    }

    return ret;
  }
};
