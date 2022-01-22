// http://leetcode.com/problems/diagonal-traverse-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
    int max_sum = 0;
    vector<int> ret;
    unordered_map<int, vector<int>> group;
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (int j = 0; j < nums[i].size(); ++j) {
        max_sum = max(max_sum, i + j);
        group[i + j].push_back(nums[i][j]);
      }
    }
    for (int i = 0; i <= max_sum; ++i) {
      for (auto n : group[i]) {
        ret.push_back(n);
      }
    }

    return ret;
  }

private:
  vector<int> findDiagonalOrderTLE(vector<vector<int>> &nums) {
    const int m = nums.size();
    int max_col = 1e5;
    // for (int i = 0; i < m; ++i) {
    //   max_col = max(max_col, int(nums[i].size()));
    // }

    vector<int> ret;
    for (int i = 0; i < m; ++i) {
      ret.push_back(nums[i][0]);

      int prev_row = i - 1;
      // start
      int prev_col = 1;
      while (prev_row >= 0) {
        if (prev_col < nums[prev_row].size()) {
          ret.push_back(nums[prev_row][prev_col]);
        }

        prev_row -= 1;
        prev_col += 1;
      }
    }

    for (int j = 1; j < max_col; ++j) {
      if (j < nums[m - 1].size()) {
        ret.push_back(nums[m - 1][j]);
      }
      int prev_row = m - 2;
      int prev_col = j + 1;
      while (prev_row >= 0) {
        if (prev_col < nums[prev_row].size()) {
          ret.push_back(nums[prev_row][prev_col]);
        }

        prev_row -= 1;
        prev_col += 1;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  so.findDiagonalOrder(input);
}
