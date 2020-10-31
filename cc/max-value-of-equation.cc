// http://leetcode.com/problems/max-value-of-equation/description/
#include "xxx.h"

class Solution {
public:
  int findMaxValueOfEquationDeq(vector<vector<int>> &p, int k) {
    deque<int> dq;
    int ret = numeric_limits<int>::min();
    // 题目最后是算
    // because xi < xj,
    // yi + yj + |xi - xj| = (yi - xi) + (yj + xj)
    // so for each point j, we find the max (yi - xi) before j
    // using deque to get maximum valid (yi - xi)
    for (int j = 0; j < p.size(); ++j) {
      // 不符合距离要求的都走开 ==> j - i <= k
      while (!dq.empty() && p[j][0] - p[dq.front()][0] > k) {
        dq.pop_front();
      }

      if (!dq.empty()) {
        ret = max(ret, p[dq.front()][1] - p[dq.front()][0] + p[j][1] + p[j][0]);
      }

      // 为了维持一个单调非递增，遇到更大的，也必须让位，这样和可以变得更大
      // 小的让出来，以此来保证最前面的那个总是最大的
      while (!dq.empty() &&
             p[dq.back()][1] - p[dq.back()][0] < p[j][1] - p[j][0]) {
        dq.pop_back();
      }

      dq.push_back(j);
    }

    return ret;
  }

  int findMaxValueOfEquation(vector<vector<int>> &p, int k) {
    priority_queue<pair<int, int>> pq;
    // 记得x的坐标好去判断区间符合k的要求
    pq.push({p[0][1] - p[0][0], p[0][0]});
    int ret = numeric_limits<int>::min();
    for (int i = 1; i < p.size(); ++i) {
      int cur = p[i][0] + p[i][1];
      while (!pq.empty() && p[i][0] - pq.top().second > k) {
        pq.pop();
      }
      if (!pq.empty()) {
        ret = max(ret, cur + pq.top().first);
      }
      pq.push({p[i][1] - p[i][0], p[i][0]});
    }

    return ret;
  }
};
