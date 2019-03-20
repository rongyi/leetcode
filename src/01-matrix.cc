// http://leetcode.com/problems/01-matrix/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    m_ = m;
    n_ = n;
    dirs_ = vector<vector<int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j]) {
          matrix[i][j] = numeric_limits<int>::max();
        } else {
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (auto d : dirs_) {
        auto nx = cur.first + d[0];
        auto ny = cur.second + d[1];
        if (valid(nx, ny) &&
            matrix[nx][ny] > matrix[cur.first][cur.second] + 1) {
          matrix[nx][ny] = matrix[cur.first][cur.second] + 1;
          q.push({nx, ny});
        }
      }
    }

    return matrix;
  }

private:
  // is (x, y) in range?
  bool valid(int x, int y) {
    if (x < 0 || x >= m_ || y < 0 || y >= n_) {
      return false;
    }
    return true;
  }

private:
  vector<vector<int>> dirs_;
  int m_;
  int n_;
};

int main() {
  Solution so;
  vector<vector<int>> input{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  auto ret = so.updateMatrix(input);
  for (auto r : ret) {
    for (auto c : r) {
      cout << c << " ";
    }
    cout << endl;
  }
}
