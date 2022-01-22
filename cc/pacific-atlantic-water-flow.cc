// http://leetcode.com/problems/pacific-atlantic-water-flow/description/
#include "xxx.hpp"

// TODO: ADD cache for success node
class Solution {
public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
    vector<pair<int, int>> ret;
    const int m = matrix.size();
    if (m == 0) {
      return ret;
    }
    const int n = matrix[0].size();
    if (n == 0) {
      return ret;
    }
    m_ = m;
    n_ = n;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (both(matrix, i, j)) {
          ret.push_back({i, j});
        }
      }
    }

    return ret;
  }

private:
  bool both(vector<vector<int>> &matrix, int x, int y) {
    unordered_set<int> c1;
    unordered_set<int> c2;
    return pacific(matrix, x, y, c1) && atlantic(matrix, x, y, c2);
  }

  bool pacific(vector<vector<int>> &matrix, int x, int y,
               unordered_set<int> &cache) {
    cache.insert(x * n_ + y);
    if (x == 0 || y == 0) {
      return true;
    }
    // cout << "pacific" << x << "   " << y << endl;
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (auto dir : dirs) {
      int ni = x + dir[0];
      int ny = y + dir[1];
      // cout << "check " << ni << "   " << ny << endl;
      // cout  << "after check" << x * n_ + y <<  "xxxx" << cache.count(ni * n_ + ny) << endl;
      if (ni < 0 || ni >= m_ || ny < 0 || ny >= n_ ||
          cache.count(ni * n_ + ny) > 0 || matrix[ni][ny] > matrix[x][y]) {
        continue;
      }
      // cout << "pa go to " << ni << "   " << ny << endl;
      auto check = pacific(matrix, ni, ny, cache);
      if (check) {
        return true;
      }
    }
    return false;
  }
  bool atlantic(vector<vector<int>> &matrix, int x, int y,
                unordered_set<int> &cache) {
    cache.insert(x * n_ + y);
    if (x == m_ - 1 || y == n_ - 1) {
      return true;
    }
    // cout << "atlantic" << x << "   " << y << endl;
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (auto dir : dirs) {
      int ni = x + dir[0];
      int ny = y + dir[1];
      if (ni < 0 || ni >= m_ || ny < 0 || ny >= n_ ||
          cache.count(ni * n_ + ny) > 0 || matrix[ni][ny] > matrix[x][y]) {
        continue;
      }
      auto check = atlantic(matrix, ni, ny, cache);
      if (check) {
        return true;
      }
    }
    return false;
  }

private:
  int m_;
  int n_;
};

int main() {
  Solution so;
  vector<vector<int>> input{{{1, 2, 2, 3, 5},
                             {3, 2, 3, 4, 4},
                             {2, 4, 5, 3, 1},
                             {6, 7, 1, 4, 5},
                             {5, 1, 1, 2, 4}}};
  auto ret = so.pacificAtlantic(input);
  for (auto p : ret) {
    cout << p.first << " -> " << p.second << endl;
  }

  // unordered_set<int> cache;
  // auto ret = so.atlantic(input, 0, 0, cache);

  // auto ret = so.both(input, 0, 0);
  // cout << ret << endl;


  // cout << "------" << endl;
  // unordered_set<int> cache;
  // auto xxx = so.pacific(input, 4, 1, cache);
  // cout << xxx << endl;
}
