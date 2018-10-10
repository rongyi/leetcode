// http://leetcode.com/problems/unique-binary-search-trees/description/
#include "one.h"
class Solution {
public:
  int numTrees(int n) {
    // f(n) = f(n-1)f(0) + f(n-2)f(1) + f(n-3)f(2) + ... + f(1)f(n-2) +  f(n-1)f(0)
    // ​      i
    // f(i)=∑   f(k−1)xf(i−k)
    // ​      k=1
    //
    vector<int> ret(n + 1, 0);
    ret[0] = 1;
    ret[1] = 1;
    ret[2] = 2;

    for (int i = 3; i <= n; ++i) {
      for (int j = i - 1; j >= 0; j--) {
        ret[i] += ret[j] * ret[i - j - 1];
      }
    }

    return ret[n];
  }
};
