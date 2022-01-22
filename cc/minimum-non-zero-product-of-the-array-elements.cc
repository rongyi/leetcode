// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/
#include "xxx.hpp"

// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/discuss/1403913/Python-math-oneliner-with-proof-explained
class Solution {
public:
  int minNonZeroProduct(int p) {
    long long cnt = (1ll << p) - 1;
    long long mod = 1e9 + 7;

    return cnt % mod * modPow(cnt - 1, cnt / 2, mod) % mod;
  }

private:
  // (x ^ y) % m
  int modPow(long long x, long long y, int m) {
    if (y == 0) {
      return 1;
    }
    long long p = modPow(x, y / 2, m);
    long long ret = (p * p) % m;

    if (y & 0x1) {
      return (ret * (x % m)) % m;
    }

    return ret;
  }
};
