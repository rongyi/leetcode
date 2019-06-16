// http://leetcode.com/problems/walking-robot-simulation/description/
#include "xxx.h"

class Solution {
public:
  // 又是被喷的表达不清楚的题目
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    // 顺时针一个圆，注意方向
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ret = 0;
    int cur_dir = 0;
    int x = 0;
    int y = 0;

    unordered_set<string> obs;
    for (auto &curobs : obstacles) {
      obs.insert(to_string(curobs[0]) + "#" + to_string(curobs[1]));
    }
    for (int i = 0; i < commands.size(); i++) {
      if (commands[i] == -2) {
        cur_dir--;
      } else if (commands[i] == -1) {
        cur_dir++;
      } else {
        for (int j = 0; j < commands[i]; j++) {
          string pos = to_string(x + dirs[cur_dir][0]) + "#" +
                       to_string(y + dirs[cur_dir][1]);
          if (obs.find(pos) != obs.end()) {
            break;
          }

          x += dirs[cur_dir][0];
          y += dirs[cur_dir][1];
        }
        ret = max(ret, x * x + y * y);
      }
      if (cur_dir == -1) {
        cur_dir = 3;
      }
      if (cur_dir == 4) {
        cur_dir = 0;
      }
    }
    return ret;
  }
};
