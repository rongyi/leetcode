// https://leetcode.com/problems/maximum-points-in-an-archery-competition/
#include "xxx.hpp"

class Solution {
public:
  vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows) {
    vector<int> ret(12);

    dfs(11, 0, 0, numArrows, aliceArrows);
    for (int k = 11; k > 0; --k) {
      if (max_mask_ & (1 << k)) {
        ret[k] = aliceArrows[k] + 1;
        numArrows -= aliceArrows[k] + 1;
      }
    }

    ret[0] = numArrows;

    return ret;
  }

private:
  void dfs(int cur_index, int cur_point, int cur_mask, int left_arrow,
           vector<int> &aliceArrows) {
    if (left_arrow >= 0 && cur_point > max_point_) {
      max_point_ = cur_point;
      max_mask_ = cur_mask;
    }
    if (cur_index > 0) {
      // put arrow to this index
      dfs(cur_index - 1, cur_point + cur_index, cur_mask + (1 << cur_index),
          left_arrow - aliceArrows[cur_index] - 1, aliceArrows);
      // don't put arrow
      dfs(cur_index - 1, cur_point, cur_mask, left_arrow, aliceArrows);
    }
  }

private:
  int max_mask_;
  int max_point_;
};
