// https://leetcode.com/problems/sum-in-a-matrix/
#include "xxx.hpp"

class Solution {
public:
  int matrixSum(vector<vector<int>> &nums) {
    int m = nums.size();
    int n = nums[0].size();

    for (auto &r : nums) {
      sort(r.rbegin(), r.rend());
    }
    int sum = 0;
    for (int j = 0; j < n; j++) {
      int val = nums[0][j];
      for (int i = 1; i < m; i++) {
        val = max(val, nums[i][j]);
      }
      //cout << "val" << val << endl;

      sum += val;
    }

    return sum;
  }
};
