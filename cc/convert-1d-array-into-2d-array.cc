// https://leetcode.com/problems/convert-1d-array-into-2d-array/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
    int sz = original.size();
    if (m * n != sz) {
      // empy one layer is enough
      return {};
    }

    vector<vector<int>> ret(m, vector<int>(n, 0));
    for (int i = 0; i < sz; ++i) {
      ret[i / n][i % n] = original[i];
    }

    return ret;
  }
};

