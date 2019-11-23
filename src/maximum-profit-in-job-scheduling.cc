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
      // 按startTime排序
      times[startTime[i]] = 0;
      jobs[startTime[i]].push_back({endTime[i], profit[i]});
    }

    int ret = 0;
    for (auto it = times.rbegin(); it != times.rend(); ++it) {
      for (auto job : jobs[it->first]) {
        // 出彩之处在于这里，意思就是能续上，lower_bound本身就是>=
        // 也即不搭界，时间没有重叠 那么不搭界的话当然可以续上，这样一直加上来
        auto it = times.lower_bound(job.first);
        ret = max(ret, (it == times.end() ? 0 : it->second) + job.second);
      }
      it->second = ret;
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> start{1, 2, 3, 4, 6};
  vector<int> end{3, 5, 10, 6, 9};
  vector<int> profit{20, 20, 100, 70, 60};
  so.jobScheduling(start, end, profit);
}
