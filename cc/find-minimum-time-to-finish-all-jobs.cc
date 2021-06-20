// http://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/description/
#include "xxx.h"

class Solution {
public:
  int minimumTimeRequired(vector<int> &jobs, int k) {
    int sum = accumulate(jobs.begin(), jobs.end(), 0);
    sort(jobs.rbegin(), jobs.rend());

    int l = jobs[0];
    int r = sum;
    while (l < r) {
      auto mid = (l + r) / 2;
      vector<int> worker(k, 0);
      if (dfs(jobs, worker, 0, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return l;
  }
  bool dfs(vector<int> &jobs, vector<int> &worker, int cur_idx, int target) {
    if (cur_idx >= jobs.size()) {
      return true;
    }
    int cur = jobs[cur_idx];

    // 尝试分配任务
    for (int i = 0; i < worker.size(); ++i) {
      if (worker[i] + cur <= target) {
        worker[i] += cur;
        if (dfs(jobs, worker, cur_idx + 1, target)) {
          return true;
        }
        worker[i] -= cur;
      }
      // 分不上
      if (worker[i] == 0) {
        break;
      }
    }

    return false;
  }
};
