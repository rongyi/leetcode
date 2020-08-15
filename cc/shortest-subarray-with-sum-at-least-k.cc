// http://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/
#include "xxx.h"

class Solution {
public:
  int shortestSubarray(vector<int> &A, int K) {
    const int n = A.size();
    int ret = n + 1;
    // prefix sum
    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + A[i];
    }
    deque<int> dq;
    for (int i = 0; i < n + 1; i++) {
      while (dq.size() > 0 && sum[i] - sum[dq.front()] >= K) {
        ret = min(ret, i - dq.front());
        dq.pop_front();
      }
      // dq要维持一个递增序列，所以遇到小的，把最后的大的弹出来
      while (dq.size() > 0 && sum[i] <= sum[dq.back()]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }

    return ret <= n ? ret : -1;
  }
};
