// http://leetcode.com/problems/count-primes/description/
#include "xxx.hpp"

class Solution {
public:
  int countPrimes(int n) {
    vector<int> seen(n, false);

    int cnt = 0;
    for (long long i = 2; i < n; i++) {
      if (seen[i]) {
        continue;
      }
      cnt++;
      // why i * i not i * 2?
      // because when you arrive to i check
      // all the number i * 2/ i * 3 / i * (i - 1) are been checked
      // because they are divisible by 2 3 .... (i - 1)
      for (long long j = i * i; j < n; j += i) {
        seen[j] = 1;
      }
    }
    return cnt;
  }
};
