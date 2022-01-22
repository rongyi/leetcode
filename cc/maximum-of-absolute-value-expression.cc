// http://leetcode.com/problems/maximum-of-absolute-value-expression/description/
#include "xxx.hpp"

class Solution {
public:
  int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2) {
    int ret = 0;
    vector<vector<int>> sign = {{1, 1, 1},   {-1, 1, 1},  {1, -1, 1},
                                {1, 1, -1},  {1, -1, -1}, {-1, -1, 1},
                                {-1, 1, -1}, {-1, -1, -1}};
    for (auto s : sign) {
      int mini = numeric_limits<int>::max();
      int maxi = numeric_limits<int>::min();
      for (int i = 0; i < arr1.size(); ++i) {
        mini = min(mini, s[0] * arr1[i] + s[1] * arr2[i] + s[2] * i);
        maxi = max(maxi, s[0] * arr1[i] + s[1] * arr2[i] + s[2] * i);
      }
      ret = max(ret, maxi - mini);
    }

    return ret;
  }
};
