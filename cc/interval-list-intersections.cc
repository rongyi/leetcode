// http://leetcode.com/problems/interval-list-intersections/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &A,
                                           vector<vector<int>> &B) {
    const int m = A.size();
    const int n = B.size();
    int i = 0;
    int j = 0;
    vector<vector<int>> ret;
    while (i < m && j < n) {
      auto cura = A[i];
      auto curb = B[j];
      // 没有相交的地方
      //      -----
      // ----
      if (cura[0]> curb[1]) {
        j++;
        continue;
      }
      // ----
      //      -----
      if (cura[1] < curb[0]) {
        i++;
        continue;
      }

      // 现在有相交的地方
      ret.push_back({max(cura[0], curb[0]), min(cura[1], curb[1])});
      // 轮到谁走？只有长的才可能在下一轮相遇
      if (cura[1] == curb[1]) {
        i++;
        j++;
      } else if (cura[1] > curb[1]) {
        j++;
      } else {
        i++;
      }
    }
    return ret;
  }
};
