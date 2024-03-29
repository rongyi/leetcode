// http://leetcode.com/problems/grid-illumination/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> gridIllumination(int N, vector<vector<int>> &lamps,
                               vector<vector<int>> &queries) {
    vector<int> ret;
    unordered_map<int, unordered_set<int>> ls;
    // 代表这个方向上还有多少盏灯在支撑着
    unordered_map<int, int> x;
    unordered_map<int, int> y;
    // 对角线(左下 -- 右上)
    unordered_map<int, int> a_d;
    // 对角线(左上 -- 右下)
    unordered_map<int, int> d_d;
    for (auto l : lamps) {
      auto i = l[0];
      auto j = l[1];
      if (ls[i].insert(j).second) {
        ++x[i];
        ++y[j];
        ++a_d[i + j];
        ++d_d[i - j];
      }
    }
    for (auto q : queries) {
      auto i = q[0];
      auto j = q[1];
      if (x[i] || y[j] || a_d[i + j] || d_d[i - j]) {
        ret.push_back(1);
        for (auto li = i - 1; li <= i + 1; ++li) {
          for (auto lj = j - 1; lj <= j + 1; ++lj) {
            if (ls[li].erase(lj)) {
              --x[li];
              --y[lj];
              --a_d[li + lj];
              --d_d[li - lj];
            }
          }
        }
      } else {
        ret.push_back(0);
      }
    }
    return ret;
  }
};
