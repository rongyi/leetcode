// http://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/
#include "xxx.h"

class Solution {
public:
  int minSwaps(vector<vector<int>> &grid) {
    const int n = grid.size();
    vector<int> zero(n, 0);
    for (int i = 0; i < grid.size(); ++i) {
      int cur_count = 0;
      for (int j = n - 1; j >= 0; --j) {
        if (grid[i][j] == 0) {
          cur_count++;
        } else {
          break;
        }
      }
      zero[i] = cur_count;
    }

    int ret = 0;

    for (int i = 0; i < n; ++i) {
      int end = i;
      int expect_zero = n - i - 1;
      while (end < n && zero[end] < expect_zero) {
        end++;
      }
      if (end == n) {
        return -1;
      }
      ret += end - i;
      // bubble sort
      while (end > i) {
        zero[end] = zero[end - 1];
        end--;
      }
    }
    return ret;
  }
};
