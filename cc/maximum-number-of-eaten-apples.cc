// http://leetcode.com/problems/maximum-number-of-eaten-apples/description/
#include "xxx.hpp"

class Solution {
public:
  int eatenApples(vector<int> &apples, vector<int> &days) {
    using p = pair<int, int>;
    priority_queue<p, vector<p>, greater<p>> pq;
    const int n = apples.size();
    int ret = 0;
    int i = 0;
    while (i < n || !pq.empty()) {
      if (i < n && apples[i] > 0) {
        pq.push({i + days[i] - 1, apples[i]});
      }
      while (pq.size() && pq.top().first < i) {
        pq.pop();
      }
      if (pq.size()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.second > 1) {
          pq.push({cur.first, cur.second - 1});
        }
        ++ret;
      }
      ++i;
    }

    return ret;
  }
};
