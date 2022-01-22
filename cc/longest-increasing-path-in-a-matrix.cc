// http://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
#include "xxx.hpp"

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    m_ = matrix.size();
    if (m_ == 0) {
      return 0;
    }
    directions_ = vector<vector<int>>{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    n_ = matrix[0].size();
    // path cache
    path_ = vector<vector<int>>(m_, vector<int>(n_, -1));

    int ret = 0;
    for (int i = 0; i < m_; i++) {
      for (int j = 0; j < n_; j++) {
        if (path_[i][j] == -1) {
          ret = max(ret, startFromHere(matrix, i, j));
        }
      }
    }

    return ret;
  }

private:
  int startFromHere(vector<vector<int>> &matrix, int i, int j) {
    if (path_[i][j] != -1) {
      return path_[i][j];
    }
    // conainer only itself
    path_[i][j] = 1;
    for (int d = 0; d < directions_.size(); d++) {
      auto ni = i + directions_[d][0];
      auto nj = j + directions_[d][1];
      // out of boundry or just smaller than the origin
      // 要求纯递增，所以相等也要排除
      if (ni < 0 || ni >= m_ || nj < 0 || nj >= n_ ||
          matrix[ni][nj] <= matrix[i][j]) {
        continue;
      }
      path_[i][j] = max(path_[i][j], 1 + startFromHere(matrix, ni, nj));
    }

    return path_[i][j];
  }

private:
  vector<vector<int>> directions_;
  int m_;
  int n_;
  vector<vector<int>> path_;
};

int main() {
  Solution so;
  vector<vector<int>> input{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
  auto ret = so.longestIncreasingPath(input);
  cout << ret << endl;
}
