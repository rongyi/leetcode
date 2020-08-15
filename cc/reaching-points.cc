// https://leetcode.com/problems/reaching-points/description/

#include "xxx.h"

class Solution {
public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    if (tx < sx || ty < sy) {
      return false;
    }
    if (tx == sx && (ty - sy) % sx == 0) {
      return true;
    }
    if (ty == sy && (tx - sx) % sy == 0) {
      return true;
    }
    return reachingPoints(sx, sy, tx % ty, ty % tx);
  }
};
