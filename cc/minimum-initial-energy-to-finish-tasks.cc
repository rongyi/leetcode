// http://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/
#include "xxx.hpp"

class Solution {
public:
  int minimumEffort(vector<vector<int>> &tasks) {
    // 启动燃料和消耗差最多的先来，能省最多的先来
    sort(tasks.rbegin(), tasks.rend(), [](vector<int> &l, vector<int> &r) {
      return l[1] - l[0] < r[1] - r[0];
    });
    int ret = 0;
    int prev_save = 0; // 前面省下来的

    for (int i = 0; i < tasks.size(); ++i) {
      int cur_cost = tasks[i][0];
      int cur_min = tasks[i][1]; // 这一轮的启动资金
      // 前面省下来的不够，自然要外来添加了
      if (cur_min > prev_save) {
        //  外面补这么多，来保证可以启动
        ret += (cur_min - prev_save);
        // 此时消耗光了，省下来的就是这一轮的
        // 从这一轮重新开始
        prev_save = (cur_min - cur_cost);
      } else {
        // 前面剩的够启动了，直接减
        prev_save -= cur_cost;
      }
    }

    return ret;
  }
};
