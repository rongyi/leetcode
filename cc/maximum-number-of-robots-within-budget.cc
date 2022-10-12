// https://leetcode.com/problems/maximum-number-of-robots-within-budget/
#include "xxx.hpp"

class Solution {
public:
  int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts,
                    long long budget) {
    deque<int> q;
    int i = 0;
    int j = 0;
    int sz = chargeTimes.size();
    long long cost = 0;
    for (; i < sz; ++i) {
      cost += runningCosts[i];
      while (!q.empty() && q.back() < chargeTimes[i]) {
        q.pop_back();
      }
      q.push_back(chargeTimes[i]);
      if (cost * (i - j + 1) + q.front() > budget) {
        cost -= runningCosts[j];
        if (q.front() == chargeTimes[j]) {
          q.pop_front();
        }
        j++;
      }
    }
    return sz - j;
  }
};
