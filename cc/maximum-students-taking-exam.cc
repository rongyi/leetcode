// http://leetcode.com/problems/maximum-students-taking-exam/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/maximum-students-taking-exam/discuss/503686/A-simple-tutorial-on-this-bitmasking-problem
  int maxStudents(vector<vector<char>> &seats) {
    const int m = seats.size();
    const int n = seats[0].size();

    vector<int> validity;
    for (int i = 0; i < m; i++) {
      int cur = 0;
      for (int j = 0; j < n; j++) {
        cur = cur * 2 + (seats[i][j] == '.');
      }
      validity.push_back(cur);
    }

    vector<vector<int>> f(m + 1, vector<int>(1 << n, -1));

    f[0][0] = 0;
    for (int i = 1; i <= m; i++) {
      int valid = validity[i - 1];

      for (int j = 0; j < (1 << n); j++) {
        // j is a subset of valid
        // no adjancent students in the row
        if ((j & valid) == j && !(j & (j >> 1))) {
          // f[i][j] transition from f[i - 1][k]
          for (int k = 0; k < (1 << n); ++k) {
            if (!(j & (k >> 1)) && !((j >> 1) & k) && f[i - 1][k] != -1) {
              // 前一排的左右两个位置没人
              // 以及上一排是valid的
              f[i][j] = max(f[i][j], f[i - 1][k] + __builtin_popcount(j));
            }
          }
        }
      }
    }

    return *max_element(f[m].begin(), f[m].end());
  }
};
