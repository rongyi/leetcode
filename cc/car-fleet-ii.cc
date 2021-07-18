// http://leetcode.com/problems/car-fleet-ii/description/
#include "xxx.h"

class Solution {
public:
  // 0 -> pos
  // 1 -> veclocity
  vector<double> getCollisionTimes(vector<vector<int>> &cars) {
    const int n = cars.size();
    vector<double> ret(n, 0);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
      // 速度比当前的车快，永远也碰不到
      // 在后面的车速度比当前快，早跑没影了
      while (s.size() && cars[s.top()][1] >= cars[i][1]) {
        s.pop();
      }
      // s中剩下来的都是速度不如当前i的
      double cur_time = -1;
      while (s.size()) {
        // 速度差 * t = 距离差
        // --> t = 距离差 / 速度差
        cur_time = 1.0 * (cars[s.top()][0] - cars[i][0]) /
                   (cars[i][1] - cars[s.top()][1]);
        // 1. 前面那辆车速度是最慢的，碰不到别人，那么迎接当前车追尾吧
        // 2.
        // 前面那辆车碰到别人的时间，与当前车碰到他的时间相比还要长一点，那么迎接当前车追尾吧
        if (ret[s.top()] == -1 || cur_time <= ret[s.top()]) {
          break;
        }
        // 否则这辆车就已经被撞过了，湮灭了
        s.pop();
      }
      ret[i] = cur_time;
      s.push(i);
    }

    return ret;
  }
};
