// https://leetcode.com/problems/second-minimum-time-to-reach-destination/
#include "xxx.h"

class Solution {
public:
  int secondMinimum(int n, vector<vector<int>> &edges, int time, int change) {
    // from 1 to n;
    vector<vector<int>> neibs(n + 1);
    for (auto &e : edges) {
      neibs[e[0]].push_back(e[1]);
      neibs[e[1]].push_back(e[0]);
    }
    // only care about the path length, the path node has no effect for answer
    vector<int> min_steps(n + 1, 10001);
    int steps = 0;
    queue<int> q;
    q.push(1);

    /*
     *
     *      O
     *     / \
     *    B   A ---E
     *     \ /     |
     *      D<-----
     * OBD == OAD, we won't go OAD,  but OAED is one path more, we check this
     * one as well
     */
    while (!q.empty() && steps <= min_steps[n] + 1) {
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        if (steps == min_steps[cur] || steps > min_steps[cur] + 1) {
          continue;
        }
        min_steps[cur] = min(min_steps[cur], steps);
        if (cur == n && steps > min_steps[n]) {
          return stepsToTime(steps, time, change);
        }
        for (auto nei : neibs[cur]) {
          q.push(nei);
        }
      }

      steps++;
    }
    return stepsToTime(min_steps[n] + 2, time, change);
  }

private:
  // change: interval from green to red, all the world changes
  // time: cost for an edge, all edges are equal
  int stepsToTime(int steps, int time, int change) {
    int ret = 0;
    // just makesure /2 part is less than one
    for (int i = 0; i < steps - 1; ++i) {
      ret += time;
      if ((ret / change) % 2) {
        ret = (ret / change + 1) * change;
      }
    }

    return ret + time;
  }
};
