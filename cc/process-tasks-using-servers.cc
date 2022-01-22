// http://leetcode.com/problems/process-tasks-using-servers/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
    // ready_time, weight, index
    using i3 = array<int, 3>;
    priority_queue<i3, vector<i3>, greater<i3>> idle;
    priority_queue<i3, vector<i3>, greater<i3>> busy;
    vector<int> ret;
    // all are available
    for (int i = 0; i < servers.size(); ++i) {
      idle.push({0, servers[i], i});
    }

    for (int cur_time = 0; cur_time < tasks.size(); ++cur_time) {
      // pick valid from busy to available
      while (!busy.empty() && (busy.top()[0] <= cur_time || idle.empty())) {
        auto [ready_time, weight, index] = busy.top();
        busy.pop();
        // then the task is comming at cur_time, this server is idle for
        // sometime, 0 means imediately
        if (ready_time <= cur_time) {
          idle.push({0, weight, index});
        } else {
          idle.push({ready_time, weight, index});
        }
      }

      // then we pop the first server
      auto [ready_time, weight, index] = idle.top();
      idle.pop();
      // two cases
      // 1. when this task is comming at cur_time, and server is ready before
      // this time
      // --------|ready_time|   ------ |cur_time|
      // the next ready_time is cur_time + tasks[cur_time](process time)
      // 2. when task is comming before ready time, this is intersting,
      // and we choose a server which is not ready actually!
      // this means the new comming task have to wait to the ready time
      // -------|cur time| ------| ready time|
      // in this case the *next* ready time is ready_time + tasks[cur_time]
      // ==> max(ready_time, cur_time)
      busy.push({max(ready_time, cur_time) + tasks[cur_time], weight, index});

      ret.push_back(index);
    }

    return ret;
  }
};
