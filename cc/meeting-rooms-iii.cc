// https://leetcode.com/problems/meeting-rooms-iii/
#include "xxx.hpp"

class Solution {
public:
  int mostBooked(int n, vector<vector<int>> &meetings) {
    sort(meetings.begin(), meetings.end());
    priority_queue<int, vector<int>, greater<int>> unused;
    using pp = pair<long long, int>;
    priority_queue<pp, vector<pp>, greater<pp>> taken;

    int max_freq = 0;
    int ret;
    map<int, int> room_freq;
    // initial all room to unused
    for (int i = 0; i < n; ++i) {
      unused.push(i);
    }
    for (auto &m : meetings) {
      auto cur_start = m[0];
      auto cur_end = m[1];
      auto duration = cur_end - cur_start;
      // cycle back rooms
      while (taken.size() > 0 && taken.top().first <= cur_start) {
        auto [_, room] = taken.top();
        taken.pop();
        unused.push(room);
      }

      // ok, we have empty room
      if (unused.size() > 0) {
        auto r = unused.top();
        unused.pop();
        room_freq[r] += 1;

        taken.push({cur_end, r});
      } else {
        // wait outside of a room which will finish soon
        auto [finsh_at, cur_room] = taken.top();
        taken.pop();
        room_freq[cur_room] += 1;
        taken.push({finsh_at + duration, cur_room});
      }
    }

    // pick max
    for (int i = n - 1; i >= 0; i--) {
      if (room_freq[i] >= max_freq) {
        ret = i;
        max_freq = room_freq[i];
      }
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<vector<int>> input{{0, 10}, {1, 5}, {2, 7}, {3, 4}};
  so.mostBooked(2, input);
  return 0;
}
