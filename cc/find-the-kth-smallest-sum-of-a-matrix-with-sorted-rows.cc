// http://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/description/
#include "xxx.h"

class Solution {
public:
  // brute force
  int kthSmallest(vector<vector<int>> &mat, int k) {
    // first row
    vector<int> cur_sum = mat[0];
    for (int i = 1; i < mat.size(); ++i) {
      vector<int> next_sum{};
      for (int j = 0; j < mat[i].size(); ++j) {
        for (auto &path : cur_sum) {
          next_sum.push_back(path + mat[i][j]);
        }
      }
      sort(next_sum.begin(), next_sum.end());
      next_sum.resize(min(k, int(next_sum.size())));

      cur_sum = move(next_sum);
    }
    return cur_sum[k - 1];
  }
};
