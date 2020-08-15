// http://leetcode.com/problems/range-addition-ii/description/
#include "xxx.h"

class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>> &ops) {
    // 最大值这里算，但是不需要最大值，只需要知道最大值有多少个
    // int cur_max = 0;
    int cur_range_x = m;
    int cur_range_y = n;
    for (auto op : ops) {
      // not valid
      if (op[0] == 0 || op[1] == 0) {
        continue;
      }
      // 太大的区间我们就只取符合范围的
      cur_range_x = min(cur_range_x, min(m, op[0]));
      cur_range_y = min(cur_range_y, min(n, op[1]));
    }
    return cur_range_x * cur_range_y;
  }
};
