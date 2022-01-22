// http://leetcode.com/problems/leetcode/ugly-number-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> index(3, 0);
    vector<int> ret(n, 0);
    ret[0] = 1;

    for (int i = 1; i < n; i++) {
      long long a = ret[index[0]] * 2;
      long long b = ret[index[1]] * 3;
      long long c = ret[index[2]] * 5;
      auto cur = min(min(a, b), c);
      // 有可能有相等的地方，所以不要用else
      if (cur == a) {
        index[0]++;
      }
      if (cur == b) {
        index[1]++;
      }
      if (cur == c) {
        index[2]++;
      }
      ret[i] = cur;
    }
    return ret[n - 1];
  }
};
