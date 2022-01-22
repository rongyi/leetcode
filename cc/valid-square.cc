// http://leetcode.com/problems/valid-square/description/
#include "xxx.hpp"

class Solution {
public:
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {
    // from the point of p1
    auto d2 = distSquare(p1, p2);
    auto d3 = distSquare(p1, p3);
    auto d4 = distSquare(p1, p4);
    // A valid square has four equal sides with positive length
    if (d2 == 0 || d3 == 0 || d4 == 0) {
      return false;
    }
    // 1. layout
    //    p1 p2 or p1 p3
    //    p3 p4    p2 p4
    if (d2 == d3 && 2 * d2 == d4 && 2 * d2 == distSquare(p2, p3)) {
      auto d24 = distSquare(p2, p4);
      return d24 == distSquare(p3, p4) && d24 == d2;
    }
    // 2. layout
    // p1 p2
    // p4 p3
    if (d2 == d4 && 2 * d2 == d3 && 2 * d2 == distSquare(p2, p4)) {
      auto d23 = distSquare(p2, p3);
      return d23 == distSquare(p4, p3) && d23 == d2;
    }

    // 3 .layout
    // p1 p3   or  p1 p4
    // p4 p2       p3 p2
    if (d3 == d4 && 2 * d3 == d2 && 2 * d3 == distSquare(p4, p3)) {
      auto d32 = distSquare(p3, p2);
      return d32 == distSquare(p4, p2) && d32 == d3;
    }

    return false;
  }
  long long distSquare(vector<int> &p1, vector<int> &p2) {
    long long d1 = p1[0] - p2[0];
    long long d2 = p1[1] - p2[1];
    return d1 * d1 + d2 * d2;
  }
};
