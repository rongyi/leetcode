// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/
#include "xxx.hpp"

class Solution {
public:
  int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                    int strength) {
    int n = tasks.size();
    int m = workers.size();
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    int lo = 0;
    int hi = min(m, n);

    int ret = 0;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int pill_used = 0;
      bool call_can_be_done = true;
      multiset<int> ws(workers.begin(), workers.end());
      // iterate task: from big to small
      for (int i = mid - 1; i >= 0; --i) {
        // big task for big worker
        auto it = prev(ws.end());
        // worker match this task
        if (tasks[i] <= *it) {
          ws.erase(it);
        } else {
          // try use pills, eat pill for smallest qualified worker
          auto it = ws.lower_bound(tasks[i] - strength);
          if (it != ws.end()) {
            pill_used++;
            ws.erase(it);
          } else {
            call_can_be_done = false;
            break;
          }
        }
        if (pill_used > pills) {
          call_can_be_done = false;
          break;
        }
      }
      if (call_can_be_done) {
        ret = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    return ret;
  }
};
