// http://leetcode.com/problems/prime-palindrome/description/
#include "xxx.h"

class Solution {
public:
  int primePalindrome(int N) {
    if (1e7 <= N && N <= 1e8) {
      N = 100030001;
    }
    while (true) {
      while (!isPalindrom(N)) {
        N++;
      }
      if (isPrime(N)) {
        return N;
      }
      N++;
    }
  }

private:
  bool isPrime(int n) {
    if (n <= 1) {
      return false;
    }
    int m = (int)(sqrt(n));
    for (int i = 2; i <= m; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
  // to string is slower than integer transformation
  int reverse(int n) {
    int m = 0;
    while (n) {
      m = m * 10 + n % 10;
      n /= 10;
    }
    return m;
  }
  bool isPalindrom(int n) { return n == reverse(n); }
};
