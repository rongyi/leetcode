// http://leetcode.com/problems/count-primes/description/
#include "xxx.hpp"

class Solution {
public:
  int countPrimes(int n) {
    int ret = 0;
    for (int i = 2; i < n; ++i) {
      if (isPrime(i)) {
        ret++;
      }
    }
    return ret;
  }
private:
  bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};
