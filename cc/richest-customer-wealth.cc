// http://leetcode.com/problems/richest-customer-wealth/description/
#include "xxx.h"

class Solution {
public:
  int maximumWealth(vector<vector<int>> &m) {
    int max_sum = 0;
    for (int i = 0; i < m.size(); ++i) {
      int cur_sum = 0;
      for (int j = 0; j < m[0].size(); ++j) {
        cur_sum += m[i][j];
      }
      max_sum = max(max_sum, cur_sum);
    }

    return max_sum;
  }
};
