// http://leetcode.com/problems/valid-boomerang/description/
#include "xxx.h"

class Solution {
public:
  bool isBoomerang(vector<vector<int>> &p) {
    // 面积不等于0
    int area = p[0][0] * (p[1][1] - p[2][1]) + p[1][0] * (p[2][1] - p[0][1]) +
      p[2][0] * (p[0][1] - p[1][1]);
    return area != 0;
  }
};
