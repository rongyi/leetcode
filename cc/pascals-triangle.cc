// http://leetcode.com/problems/pascals-triangle/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> generate(int rows) {
    vector<vector<int>> ret{{1}};
    for (int i = 2; i <= rows; i++) {
      vector<int> &prev = ret[i - 2];
      vector<int> cur_row{1};
      for (int j = 1; j < prev.size(); j++) {
        cur_row.push_back(prev[j] + prev[j - 1]);
      }
      cur_row.push_back(1);
      ret.push_back(cur_row);
    }

    return ret;
  }
};
