// http://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/description/
#include "xxx.h"

class Solution {
public:
  int minSessions(vector<int> &tasks, int sessionTime) {
    memset(dp_, -1, sizeof(dp_));
    session_time_ = sessionTime;
    int sz = tasks.size();

    // 0 means don't give the first round any time,
    // so we add round to get a nother fresh running time
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
    int ret = tasks.size();
    for (int i = 0; i < tasks.size(); ++i) {
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
  vector<int> input{3, 1, 3, 1, 1};
  Solution so;
  so.minSessions(input, 8);
}
