// https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/
#include "xxx.hpp"

class Solution {
public:
  int hardestWorker(int n, vector<vector<int>> &logs) {
    int ret = logs[0][0];
    int max_worktime = logs[0][1];
    int sz = logs.size();
    for (int i = 1; i < sz; ++i) {
      int cur_worktime = logs[i][1] - logs[i - 1][1];
      if (cur_worktime > max_worktime) {
        max_worktime = cur_worktime;
        ret = logs[i][0];
      } else if (cur_worktime == max_worktime) {
        ret = min(ret, logs[i][0]);
      }
    }

    return ret;
  }
};
