// http://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/description/
#include "xxx.hpp"

class SolutionTLE {

public:
  int minSessions(vector<int> &tasks, int sessionTime) {
    int n = tasks.size();
    return dfs(tasks, n, sessionTime, 0);
  }

private:
  int dfs(vector<int> &tasks, int n, int sessionTime, int cur_pos) {
    if (cur_pos >= n) {
      return 0;
    }
    // add current to a new sessions
    sessions_.push_back(tasks[cur_pos]);
    int ret = 1 + dfs(tasks, n, sessionTime, cur_pos + 1);
    sessions_.pop_back();

    // trying to put current in prev and make it still a valid session
    for (int i = 0; i < sessions_.size(); ++i) {
      if (sessions_[i] + tasks[cur_pos] <= sessionTime) {
        sessions_[i] += tasks[cur_pos];
        ret = min(ret, dfs(tasks, n, sessionTime, cur_pos + 1));
        sessions_[i] -= tasks[cur_pos];
      }
    }

    return ret;
  }

private:
  vector<int> sessions_;
};

class Solution {
public:
  int minSessions(vector<int> &tasks, int sessionTime) {
    memset(dp_, -1, sizeof(dp_));
    done_mask_ = (1 << tasks.size()) - 1;
    session_time_ = sessionTime;

    return help(tasks, 0, 0);
  }

private:
  int help(vector<int> &tasks, int cur_mask, int curr_time) {
    // this round is no need to continue
    if (curr_time > session_time_) {
      return tasks.size();
    }
    if (cur_mask == done_mask_) {
      return 1;
    }
    if (dp_[cur_mask][curr_time] != -1) {
      return dp_[cur_mask][curr_time];
    }
    int ret = tasks.size();

    for (int i = 0; i < tasks.size(); ++i) {
      // current task not runng yet
      // every un running task can be put in current or next
      // just keep this way and cache the result
      if ((cur_mask & (1 << i)) == 0) {
        int include_in_current =
            help(tasks, cur_mask | (1 << i), curr_time + tasks[i]);
        int include_in_next = 1 + help(tasks, cur_mask | (1 << i), tasks[i]);
        ret = min({ret, include_in_next, include_in_current});
      }
    }
    return dp_[cur_mask][curr_time] = ret;
  }

private:
  // dp[i][j] i -> task bitmask, 1 mask done
  //                             0 mask not running
  //          j -> current session running time
  int dp_[1 << 14][16];
  int done_mask_;
  int session_time_;
};

class SolutionOne {
public:
  int minSessions(vector<int> &tasks, int sessionTime) {
    memset(dp_, -1, sizeof(dp_));
    session_time_ = sessionTime;
    int sz = tasks.size();

    // 0 means don't give the first round any time,
    // so we add round to get a nother fresh running time
    // mask 1 task not running
    //      0 done
    return dfs(tasks, (1 << sz) - 1, 0);
  }

private:
  int dfs(vector<int> &tasks, int cur_mask, int cur_round_left) {
    if (cur_mask == 0) {
      return 0;
    }
    if (dp_[cur_mask][cur_round_left] != -1) {
      return dp_[cur_mask][cur_round_left];
    }
    // put one task in a session, this way we get the longest round
    int ret = tasks.size();
    for (int i = 0; i < tasks.size(); ++i) {
      // if the task is not running, schedule this task, either
      // fit in current round, or put in next fresh round
      if ((cur_mask >> i) & 1) {
        int new_mask = ~(1 << i) & cur_mask;
        if (tasks[i] <= cur_round_left) {
          ret = min(ret, dfs(tasks, new_mask, cur_round_left - tasks[i]));
        } else {
          ret = min(ret, dfs(tasks, new_mask, session_time_ - tasks[i]) + 1);
        }
      }
    }

    dp_[cur_mask][cur_round_left] = ret;

    return ret;
  }

private:
  int dp_[1 << 14][15];
  int session_time_;
};

int main() {
  vector<int> input{4, 4, 4, 4};
  Solution so;
  so.minSessions(input, 4);
}
