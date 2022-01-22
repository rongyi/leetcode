// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/
#include "xxx.hpp"

class Solution {
public:
  int smallestChair(vector<vector<int>> &times, int targetFriend) {
    int sz = times.size();
    for (int i = 0; i < sz; ++i) {
      times[i].push_back(i);
    }
    // by arriving time
    sort(times.begin(), times.end());
    using pii = pair<int, int>;
    // cycle
    // {free_time, chair_index}
    priority_queue<pii, vector<pii>, greater<pii>> occ;
    // already free
    // {valid chair index}
    priority_queue<int, vector<int>, greater<int>> ready;
    // chair start from 0
    int next_chair = 0;
    for (int i = 0; i < sz; ++i) {
      int arrive = times[i][0];
      int leave = times[i][1];
      int index = times[i][2];
      // new comming friend need a fresh chair
      int cur_chair = -1;
      // need to pop all valid to ready, this is
      // where I can't AC, need to pop all to ready
      // not just check only the top
      while (!occ.empty() && occ.top().first <= arrive) {
        ready.push(occ.top().second);
        occ.pop();
      }

      if (ready.empty()) {
        // fresh chair
        cur_chair = next_chair;
        next_chair++;
        occ.push({leave, cur_chair});
      } else {
        // cycle chair, and this chair's available time
        // should be the end of this friend leave
        cur_chair = ready.top();
        ready.pop();
        occ.push({leave, cur_chair});
      }
      if (index == targetFriend) {
        return cur_chair;
      }
    }
    return -1;
  }
};
