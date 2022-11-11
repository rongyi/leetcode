// https://leetcode.com/problems/maximum-sum-of-an-hourglass/
#include "xxx.hpp"

class Solution {
public:
  int maxSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    // first row and forst colume is all zero
    vector<vector<long long>> prefix(m + 1, vector<long long>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        prefix[i + 1][j + 1] =
            prefix[i][j + 1] + prefix[i + 1][j] + grid[i][j] - prefix[i][j];
      }
    }
    int ret = 0;
    for (int i = 0; i <= m - 3; ++i) {
      for (int j = 0; j <= n - 3; ++j) {
        int range_sum = prefix[i + 3][j + 3] - prefix[i + 3][j] -
                        prefix[i][j + 3] + prefix[i][j];
        range_sum -= (grid[i + 1][j] + grid[i + 1][j + 2]);
        ret = max(ret, range_sum);
      }
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<vector<int>> input{
      {6, 2, 1, 3}, {4, 2, 1, 5}, {9, 2, 8, 7}, {4, 1, 2, 9}};
  so.maxSum(input);
  return 0;
}
