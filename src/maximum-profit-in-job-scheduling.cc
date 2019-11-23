// http://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
#include "xxx.h"

class Solution {
public:
  // 不同的job不同的由各自的开始结束时间以及对应的收益
  // 要求是求最大收益，job不能有时间重叠的情况下
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    map<int, int> times;
    unordered_map<int, vector<pair<int, int>>> jobs;
    for (auto i = 0; i < startTime.size(); ++i) {
      times[startTime[i]] = 0;
      jobs[startTime[i]].push_back({endTime[i], profit[i]});
    }

    int ret = 0;
    for (auto it = times.rbegin(); it != times.rend(); ++it) {
      for (auto job : jobs[it->first]) {
        auto it = times.lower_bound(job.first);
        ret = max(ret, (it == end(times) ? 0 : it->second) + job.second);
      }
      it->second = ret;
    }

    return ret;
  }
};
