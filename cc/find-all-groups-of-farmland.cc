// https://leetcode.com/problems/find-all-groups-of-farmland/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> findFarmland(vector<vector<int>> &land) {
    int m = land.size();
    int n = land[0].size();
    vector<vector<int>> ret;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // this is the keypoint, 
        //    0
        //  0 1 <-- i the top left will have left and up element zero
        //
        if (land[i][j] == 1 && (i - 1 < 0 || land[i - 1][j] == 0) &&
            (j - 1 < 0 || land[i][j - 1] == 0)) {
          // top left
          int x1 = i;
          int y1 = j;
          int x2 = i;
          int y2 = j;

          // update bottom right: find 1
          while (x2 < m && land[x2][j] == 1) {
            x2++;
          }
          // now x2 stop at 0 ele or out of boudary
          x2--;
          while (y2 < n && land[i][y2] == 1) {
            y2++;
          }
          y2--;
          ret.push_back({x1, y1, x2, y2});
        }
      }
    }

    return ret;
  }
};
