// https://leetcode.com/problems/maximum-running-time-of-n-computers/
#include "xxx.hpp"

class Solution {
public:
  long long maxRunTime(int n, vector<int> &bts) {
    long long sum = accumulate(begin(bts), end(bts), 0ll);
    priority_queue<int> q(bts.begin(), bts.end());

    while (!q.empty() && q.top() > sum / n) {
      sum -= q.top();
      q.pop();
      n--;
    }

    return sum / n;
  }
};
