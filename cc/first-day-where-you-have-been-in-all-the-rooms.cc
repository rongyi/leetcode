// https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/discuss/1445203/Very-concise-C%2B%2B-DP-solution-O(n)-with-explanation
  int firstDayBeenInAllRooms(vector<int> &nextVisit) {
    using ll = long long;
    int mod = 1e9 + 7;
    int n = nextVisit.size();
    // first day to reach i
    vector<ll> f(n, 0);
    // second time to reach i
    // f[i] = (g[i - 1] + 1) % mod;
    // means to get i first time, we
    // must get to i - 1 double time,
    // for this we can add one step
    // g[i] = (f[i] + 1 + d) 1 means the step jump from i to visited[i]
    // to get i second time, we must first get to i first time
    // then jump back to visited[i] and get to i again
    // d reprent the day from visited[i] to i
    // ==> f[i] - f[visited[i]]
    vector<ll> g(n, 0);
    f[0] = 0;
    // because visited[i] <= i so visited[i] must be 0
    g[0] = 1;

    for (int i = 1; i < n; ++i) {
      f[i] = (g[i - 1] + 1) % mod;
      g[i] = (f[i] * 2 + mod - f[nextVisit[i]] + 1) % mod;
    }

    return f[n - 1] % mod;
  }

  // ofcause TLE! :(
  int firstDayBeenInAllRoomsTLE(vector<int> &nextVisit) {
    int mod = 1e9 + 7;
    int n = nextVisit.size();
    vector<int> count(n, 0);
    // day 0
    long long d = 0;
    set<int> visited;
    visited.insert(0);
    ++count[0];
    int cur_room = 0;

    while (visited.size() < n) {
      if (count[cur_room] & 1) {
        cur_room = nextVisit[cur_room];
      } else {
        cur_room = (cur_room + 1) % n;
      }
      ++count[cur_room];
      visited.insert(cur_room);
      d++;
    }

    return d % mod;
  }
};
