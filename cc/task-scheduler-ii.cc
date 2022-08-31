// https://leetcode.com/problems/task-scheduler-ii/
#include "xxx.hpp"

class Solution {
public:
  long long taskSchedulerII(vector<int> &tasks, int space) {
    map<int, long long> prev;
    long long cur_day = 0;
    for (auto &t : tasks) {
      cur_day += 1;
      if (prev.count(t) && cur_day - prev[t] <= space) {
        cur_day += space - (cur_day - prev[t]) + 1;
      }

      prev[t] = cur_day;
    }

    return cur_day;
  }
};
