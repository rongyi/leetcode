// https://leetcode.com/problems/time-to-cross-a-bridge/
#include "xxx.hpp"

class Solution {
public:
  // ┌───────────────────┐                 ┌──────────────────┐
  // │                   │                 │                  │
  // │                   ├───────────────► │                  │
  // │                   │                 │                  │
  // │                   │                 │                  │
  // │                   │                 │                  │
  // │                   │                 │                  │
  // │                   │◄────────────────┤                  │
  // │                   │                 │                  │
  // └───────────────────┘                 └──────────────────┘

  // n boxes
  // k worker
  // time: {left, up, right, down}
  int findCrossingTime(int n, int k, vector<vector<int>> &time) {
    using pii = pair<int, int>;
    // cross the bridge
    priority_queue<pii> left_to_right;
    priority_queue<pii> right_to_left;

    // worker is busy at new warehouse
    priority_queue<pii, vector<pii>, greater<pii>> busy_new;
    // worker is busy at old warehouse
    priority_queue<pii, vector<pii>, greater<pii>> busy_old;
    // initialy at left bank
    for (int i = 0; i < time.size(); ++i) {
      left_to_right.push({time[i][0] + time[i][2], i});
    }

    int cur_time = 0;

    // warehouse need be transported
    // worker need to go to new warehouse
    while (n > 0 || !busy_old.empty() || !right_to_left.empty()) {
      // move workers from warehouse to bridge side at right
      while (!busy_old.empty() && busy_old.top().first <= cur_time) {
        int i = busy_old.top().second;
        busy_old.pop();
        right_to_left.push({time[i][0] + time[i][2], i});
      }
      // move workers from warehouse to bridge side at left
      while (!busy_new.empty() && busy_new.top().first <= cur_time) {
        int i = busy_new.top().second;
        busy_new.pop();
        left_to_right.push({time[i][0] + time[i][2], i});
      }

      if (!right_to_left.empty()) {
        int i = right_to_left.top().second;
        right_to_left.pop();
        cur_time += time[i][2];
        if (n > 0) {
          busy_new.push({cur_time + time[i][3], i});
        }
      } else if (!left_to_right.empty() && n > 0) {
        int i = left_to_right.top().second;
        left_to_right.pop();
        cur_time += time[i][0];
        busy_old.push({cur_time + time[i][1], i});
        --n;
      } else {
        cur_time += 1;
      }
    }

    return cur_time;
  }
};

// int main(int argc, char *argv[]) {
// Solution so;
// vector<vector<int>> times{{1, 1, 2, 1}, {1, 1, 3, 1}, {1, 1, 4, 1}};
// so.findCrossingTime(1, 3, times);
// return 0;
//}
