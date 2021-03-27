// http://leetcode.com/problems/furthest-building-you-can-reach/description/
#include "xxx.h"

class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    cache_ = vector<vector<vector<int>>>(
        heights, vector<vector<int>>(bricks, vector<int>(ladders, 0)));
    return jump(heights, 0, bricks, ladders);
  }

private:
  int jump(vector<int> &heights, int cur_idx, int bricks, int ladders) {
    if (cur_idx == heights.size() - 1) {
      return cur_idx;
    }
    if (heights[cur_idx] >= heights[cur_idx + 1]) {
      return jump(heights, cur_idx + 1, bricks, ladders);
    }

    if (cache_[cur_idx][bricks][ladders] != 0) {
      return cache_[cur_idx][bricks][ladders];
    }
    // we need bricks or ladders
    int need_bricks = heights[cur_idx + 1] - heights[cur_idx];
    int use_brick_can_go_to = cur_idx;
    int use_ladder_can_go_to = cur_idx;
    if (bricks >= need_bricks) {
      use_brick_can_go_to =
          jump(heights, cur_idx + 1, bricks - need_bricks, ladders);
    }
    if (ladders > 0) {
      use_ladder_can_go_to = jump(heights, cur_idx + 1, bricks, ladders - 1);
    }

    return max(use_brick_can_go_to, use_ladder_can_go_to);
  }

private:
  // i, j, k
  // 站在i楼顶还有j块砖和k个梯子
  vector<vector<vector<int>>> cache_;
};
