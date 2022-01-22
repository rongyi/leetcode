// http://leetcode.com/problems/image-smoother/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
    const int m = M.size();
    const int n = M[0].size();
    dir_ = vector<vector<int>>{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1},
                               {1, -1},  {1, 0},  {1, 1},  {0, 0}};
    vector<vector<int>> ret(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ret[i][j] = calc(M, m, n, i, j);
      }
    }

    return ret;
  }

private:
  int calc(vector<vector<int>> &M, const int m, const int n, int x, int y) {
    int valid_souround = 0;
    int valid_sum = 0;
    for (auto d : dir_) {
      int nx = x + d[0];
      int ny = y + d[1];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
        continue;
      }
      valid_souround++;
      valid_sum += M[nx][ny];
    }
    return valid_sum / valid_souround;
  }

private:
  vector<vector<int>> dir_;
};
