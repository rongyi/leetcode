// https://www.lintcode.com/problem/number-of-distinct-islands-ii/description
#include "xxx.hpp"

class Solution {
public:
  /**
   * @param grid: a list of lists of integers
   * @return: return an integer, denote the number of distinct islands
   */
  int numDistinctIslands2(vector<vector<int>> &grid) {
    m_ = grid.size();
    n_ = grid[0].size();
    set<vector<pair<int, int>>> ret;

    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; j++) {
        if (grid[i][j] == 1) {
          vector<pair<int, int>> v;
          dfs(grid, i, j, i, j, v);
          ret.insert(normalize(v));
        }
      }
    }

    return ret.size();
  }

private:
  void dfs(vector<vector<int>> &grid, int ox, int oy, int x, int y,
           vector<pair<int, int>> &v) {
    if (x < 0 || x >= m_ || y < 0 || y >= n_) {
      return;
    }
    if (grid[x][y] == 1) {
      grid[x][y] = 0;
      v.push_back({x - ox, y - oy});

      // whatever the corner oder, every one just obey it
      dfs(grid, ox, oy, x + 1, y, v);
      dfs(grid, ox, oy, x - 1, y, v);
      dfs(grid, ox, oy, x, y + 1, v);
      dfs(grid, ox, oy, x, y - 1, v);
    }
  }

  vector<pair<int, int>> normalize(vector<pair<int, int>> &a) {
    vector<vector<pair<int, int>>> ret(8, vector<pair<int, int>>());
    for (auto &p : a) {
      int x = p.first, y = p.second;
      ret[0].push_back(make_pair(x, y));
      ret[1].push_back(make_pair(x, -y));
      ret[2].push_back(make_pair(-x, y));
      ret[3].push_back(make_pair(-x, -y));
      ret[4].push_back(make_pair(y, x));
      ret[5].push_back(make_pair(y, -x));
      ret[6].push_back(make_pair(-y, x));
      ret[7].push_back(make_pair(-y, -x));
    }
    for (int i = 0; i < 8; ++i) {
      sort(ret[i].begin(), ret[i].end());
      int r_offset = 0 - ret[i][0].first, c_offset = 0 - ret[i][0].second;
      for (int j = 0; j < ret[i].size(); ++j) {
        ret[i][j].first += r_offset;
        ret[i][j].second += c_offset;
      }
    }
    sort(ret.begin(), ret.end());
    return ret[0];
  }

private:
  int m_;
  int n_;
};

int main() {
  Solution so;
  vector<vector<int>> input{
      {1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}};
  auto ret = so.numberofDistinctIslands2(input);
  cout << ret << endl;
}
