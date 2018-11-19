// http://leetcode.com/problems/super-ugly-number/description/
#include "simpleone.h"

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    const int k = primes.size();
    vector<int> pos(k, 0);
    vector<int> ret(n);
    ret[0] = 1;
    for (int i = 1; i < n; i++) {
      int tmp = numeric_limits<int>::max();
      for (int j = 0; j < k; j++) {
        tmp = min(tmp, ret[pos[j]] * primes[j]);
      }
      for (int j = 0; j < k; j++) {
        if (tmp == ret[pos[j]] * primes[j]) {
          pos[j]++;
        }
      }
      ret[i] = tmp;
    }
    return ret[n - 1];
  }
};
