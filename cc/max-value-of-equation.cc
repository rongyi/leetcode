// http://leetcode.com/problems/max-value-of-equation/description/
#include "xxx.h"

class Solution {
public:
  int findMaxValueOfEquation(vector<vector<int>> &p, int k) {
    deque<int> dq;
    int ret = numeric_limits<int>::min();
    for (int j = 0; j < p.size(); ++j) {
      // 不符合距离要求的都走开 ==> j - i <= k
      while (!dq.empty() && p[j][0] - p[dq.front()][0] > k) {
        dq.pop_front();
      }

      if (!dq.empty()) {
        ret = max(ret, p[dq.front()][1] - p[dq.front()][0] + p[j][1] + p[j][0]);
      }

      // 为了维持一个单调非递增，遇到更小的，也必须让位，这样和可以变得更大
      // 小的要让出来，以此来保证最前面的那个总是最大的
      while (!dq.empty() &&
             p[dq.back()][1] - p[dq.back()][0] < p[j][1] - p[j][0]) {
        dq.pop_back();
      }

      dq.push_back(j);
    }

    return ret;
  }
};
