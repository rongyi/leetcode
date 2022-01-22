// http://leetcode.com/problems/robot-bounded-in-circle/description/
#include "xxx.hpp"

class Solution {
public:
  bool isRobotBounded(string inst) {
    // 没得走
    if (inst.find('G') == string::npos) {
      return true;
    }
    // 不带转向的走
    if (inst.find('L') == string::npos && inst.find('R') == string::npos) {
      return false;
    }
    int x = 0;
    int y = 0;
    int cur_dir = 0;
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (auto ins : inst) {
      if (ins == 'R') {
        cur_dir = (cur_dir + 1) % 4;
      } else if (ins == 'L') {
        // -1 + 4
        cur_dir = (cur_dir + 3) % 4;
      } else {
        x += dirs[cur_dir][0];
        y += dirs[cur_dir][1];
      }
    }
    //  final position does not change or the facing direction is different from
    //  the beginning.
    return (x == 0 && y == 0) || cur_dir > 0;
  }
};
