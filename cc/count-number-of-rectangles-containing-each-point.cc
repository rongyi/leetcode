// https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/
#include "xxx.hpp"

class Solution {
public:
  vector<int> countRectangles(vector<vector<int>> &rectangles,
                              vector<vector<int>> &points) {
    int sz = points.size();
    vector<int> ret(sz, 0);
    // group by y corrdinate
    // value restriction is in a very wide range but not very high range
    // so we group by y
    vector<vector<int>> groupy(101);
    for (auto &r : rectangles) {
      groupy[r[1]].push_back(r[0]);
    }
    for (int i = 0; i < groupy.size(); ++i) {
      sort(groupy[i].begin(), groupy[i].end());
    }
    for (int i = 0; i < sz; ++i) {
      int sum = 0;
      for (int j = points[i][1]; j < groupy.size(); ++j) {
        auto it = lower_bound(groupy[j].begin(), groupy[j].end(), points[i][0]);
        sum += groupy[j].end() - it;
      }

      ret[i] = sum;
    }

    return ret;
  }
};
