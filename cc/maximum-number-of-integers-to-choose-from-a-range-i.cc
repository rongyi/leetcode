// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
#include "xxx.hpp"

class Solution {
public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    set<int> banset(banned.begin(), banned.end());
    int ret = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      if (banset.count(i)) {
        continue;
      }
      sum += i;
      // oops, too big
      if (sum > maxSum) {
        break;
      }
      ret++;
    }

    return ret;
  }
};
