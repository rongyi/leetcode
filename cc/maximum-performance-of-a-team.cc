// http://leetcode.com/problems/maximum-performance-of-a-team/description/
#include "xxx.hpp"

class Solution {
public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency,
                     int k) {
    vector<pair<int, int>> espairs;
    for (int i = 0; i < n; ++i) {
      espairs.push_back({efficiency[i], speed[i]});
    }
    sort(espairs.begin(), espairs.end());

    const int mod = pow(10, 9) + 7;
    priority_queue<int, vector<int>, greater<int>> pq;

    long sum = 0;
    long ret = 0;
    for (int i = n - 1; i >= 0; --i) {
      sum += espairs[i].second;
      pq.push(espairs[i].second);
      // 通过pq来判断取多少个了
      if (pq.size() > k) {
        sum -= pq.top();
        pq.pop();
      }
      // 最小的那个
      ret = max(ret, sum * espairs[i].first);
    }

    return ret % mod;
  }
};
