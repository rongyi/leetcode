// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
#include "xxx.hpp"

class Solution {
public:
  bool checkValid(vector<vector<int>> &matrix) {
    int sz = matrix.size();
    // sum for each row
    vector<set<int>> rows(sz);
    // sum for each col
    vector<set<int>> cols(sz);
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        int cur = matrix[i][j];
        if (rows[i].find(cur) != rows[i].end()) {
          return false;
        }
        if (cols[j].find(cur) != cols[j].end()) {
          return false;
        }
        rows[i].insert(cur);
        cols[j].insert(cur);
      }
    }
    for (int i = 0; i < sz; ++i) {
      if (rows[i].size() != sz) {
        return false;
      }
      if (cols[i].size() != sz) {
        return false;
      }
    }

    return true;
  }
};
