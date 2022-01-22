// http://leetcode.com/problems/minimum-jumps-to-reach-home/description/
#include "xxx.hpp"

class Solution {
public:
  int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
    unordered_set<int> banindex(forbidden.begin(), forbidden.end());
    // 防止打环，不能跳过来跳过去,一个点至多从两个方向各过来一次，相同方向过来两次说明就打环,
    // 在做无意义的跳转
    vector<pair<bool, bool>> visited(6000, {false, false});
    visited[0].first = true;

    // pos, isjumpbackward?
    queue<pair<int, bool>> q;
    q.push({0, false});
    int step = 0;
    while (q.size()) {
      int sz = q.size();
      while (sz--) {
        auto cur_pos = q.front().first;
        auto is_backward = q.front().second;
        q.pop();
        if (cur_pos == x) {
          return step;
        }
        // jump forward
        int next_jump = cur_pos + a;
        // 6000也是个magic
        if (next_jump < 6000 && banindex.count(next_jump) == 0 &&
            !visited[next_jump].first) {
          q.push({next_jump, false});
          visited[next_jump].first = true;
        }

        // jump backward
        if (!is_backward) {
          next_jump = cur_pos - b;
          if (next_jump >= 0 && banindex.count(next_jump) == 0 &&
              !visited[next_jump].second) {
            q.push({next_jump, true});
            visited[next_jump].second = true;
          }
        }
      }
      step++;
    }

    return -1;
  }
};
