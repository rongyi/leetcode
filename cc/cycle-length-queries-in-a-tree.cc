// https://leetcode.com/problems/cycle-length-queries-in-a-tree/
#include "xxx.hpp"

class Solution {
public:
  vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries) {
    int sz = queries.size();
    vector<int> ret(sz, 1);
    for (int i = 0; i < sz; ++i) {
      int l = queries[i][0];
      int r = queries[i][1];
      while (l != r) {
        if (l < r) {
          r /= 2;
        } else {
          l /= 2;
        }

        ret[i]++;
      }
    }

    return ret;
  }
};
