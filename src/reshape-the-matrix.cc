// http://leetcode.com/problems/reshape-the-matrix/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
    const int m = nums.size();
    const int n = nums[0].size();
    if (m * n != r * c) {
      return nums;
    }
    vector<vector<int>> reshape(r, vector<int>(c, 0));
    for (int i = 0; i < r * c; i++) {
      reshape[i / c][i % c] = nums[i / n][i % n];
    }

    return reshape;
  }
};
