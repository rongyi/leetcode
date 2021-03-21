// http://leetcode.com/problems/rank-transform-of-a-matrix/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> lst;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        lst.push_back({matrix[i][j], i, j});
      }
    }
    sort(lst.begin(), lst.end(),
         [](auto &l, auto &r) -> bool { return l[0] < r[0]; });
    vector<int> rows(m);
    vector<int> cols(n);
    // now values are collected in lst, so we can reuse matrix

    int last_val = numeric_limits<int>::min();
    vector<pair<int, int>> points;
    for (auto &l : lst) {
      auto val = l[0];
      auto x = l[1];
      auto y = l[2];
      if (val != last_val) {
        process(matrix, points, rows, cols);
        last_val = val;
        points.clear();
      }
      points.push_back({x, y});
    }

    process(matrix, points, rows, cols);
    return matrix;
  }

private:
  void process(vector<vector<int>> &matrix, vector<pair<int, int>> &points,
               vector<int> &rows, vector<int> &cols) {
    vector<int> ds(matrix.size() + matrix[0].size(), -1);
    for (auto &p : points) {
      auto pi = find(ds, p.first);
      auto pj = find(ds, p.second + rows.size());
      if (pi != pj) {
        ds[pi] = min({ds[pi], ds[pj], -max(rows[p.first], cols[p.second]) - 1});
        ds[pj] = pi;
      }
    }
    for (auto &p : points) {
      matrix[p.first][p.second] = rows[p.first] = cols[p.second] =
          -ds[find(ds, p.first)];
    }
  }

  int find(vector<int> &ds, int i) {
    if (ds[i] < 0) {
      return i;
    }

    return ds[i] = find(ds, ds[i]);
  }
};
