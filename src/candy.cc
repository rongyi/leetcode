// http://leetcode.com/problems/candy/description/
#include "one.h"

class Solution {
public:
  int candy(vector<int> &ratings) {
    const int n = ratings.size();
    if (n == 0) {
      return 0;
    }
    // 这里算的是相对值
    vector<int> peak(n, 0);
    // 多的情况下至少比别人多一块
    int candy = 1;
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) {
        peak[i] = candy++;
      } else {
        // 最少的一块
        candy = 1;
      }
    }
    candy = 1;
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        // 这里一方面candy继续加，一方面这个值要两边最高的才能两边都满足
        peak[i] = max(candy++, peak[i]);
      } else {
        candy = 1;
      }
    }
    // 每个小朋友至少一块，分配n块
    return accumulate(peak.begin(), peak.end(), n);
  }
};
