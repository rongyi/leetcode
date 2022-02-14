// https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/
#include "xxx.hpp"

class Solution {
public:
  int minCost(vector<int> &startPos, vector<int> &homePos,
              vector<int> &rowCosts, vector<int> &colCosts) {
    int ret = 0;

    // robot will always go through those boudaries
    int dr = (startPos[0] < homePos[0]) ? 1 : -1;
    int dc = (startPos[1] < homePos[1]) ? 1 : -1;
    for (int r = startPos[0]; r != homePos[0]; r += dr) {
      ret += rowCosts[r + dr];
    }
    for (int c = startPos[1]; c != homePos[1]; c += dc) {
      ret += colCosts[c + dc];
    }

    return ret;
  }
};
