// http://leetcode.com/problems/prime-arrangements/description/
#include "xxx.h"

class Solution {
public:
  // 有点二
  int numPrimeArrangements(int n) {
    const int mod = pow(10, 9) + 7;
    int prime = 1;
    long long ret = 1;
    for (int i = 3; i <= n; ++i) {
      if (isPrime(i)) {
        ++prime;
      }
    }
    // all permutations of primes == factorial of primes
    for (int i = 1; i <= prime; ++i) {
      ret = ret * i % mod;
    }
    // all permutations of non-primes == factorial of non-primes
    for (int i = 1; i <= n - prime; ++i) {
      ret = ret * i % mod;
    }

    return ret;
  }

private:
  bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};
