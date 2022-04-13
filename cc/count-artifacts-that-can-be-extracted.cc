// https://leetcode.com/problems/count-artifacts-that-can-be-extracted/
#include "xxx.hpp"

// shitty problem
class Solution {
public:
  int digArtifacts(int n, vector<vector<int>> &artifacts,
                   vector<vector<int>> &dig) {
    // how about dig means render
    vector<vector<int>> ground(n, vector<int>(n, 0));
    for (auto &d : dig) {
      ground[d[0]][d[1]] = 1;
    }
    int ret = 0;
    for (auto &art : artifacts) {
      int start_row = art[0];
      int start_col = art[1];
      int end_row = art[2];
      int end_col = art[3];
      bool valid = true;
      for (int i = start_row; i <= end_row; ++i) {
        for (int j = start_col; j <= end_col; ++j) {
          if (ground[i][j] == 0) {
            valid = false;
            // two layer break
            goto out;
          }
        }
      }
    out:
      if (valid) {
        ret++;
      }
    }

    return ret;
  }
};
