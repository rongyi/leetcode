// https://leetcode.com/problems/find-the-pivot-integer/
#include "xxx.hpp"

class Solution {
public:
  int pivotInteger(int n) {
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      prefix[i] = prefix[i - 1] + i;
    }

    for (int i = 1; i <= n; ++i) {
      if (prefix[i] == (prefix[n] - prefix[i - 1])) {
        return i;
      }
    }
    return -1;
  }
};
