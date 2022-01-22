// http://leetcode.com/problems/furthest-building-you-can-reach/description/
#include "xxx.hpp"

class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    // 小顶堆
    priority_queue<int, vector<int>, greater<int>> pq;

    // 对梯子要省着用
    for (int i = 0; i < heights.size() - 1; ++i) {
      int d = heights[i + 1] - heights[i];
      if (d <= 0) {
        continue;
      }
      pq.push(d);
      // 梯子用在哪里？ 坑最深的地方
      // pq.size() 表示有这么多坑，
      // 大于ladders就表示一定要使用砖头了，但优先放在哪里呢？
      // 放在比较浅的地方，因为深的可以用ladder替代
      if (pq.size() > ladders) {
        bricks -= pq.top();
        pq.pop();
        // 这一关过不去，停在这里
        if (bricks < 0) {
          return i;
        }
      }
    }

    return heights.size() - 1;
  }
  //   int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
  //     return jump(heights, 0, bricks, ladders);
  //   }

  // private:
  //   int jump(vector<int> &heights, int cur_idx, int bricks, int ladders) {
  //     if (cur_idx == heights.size() - 1) {
  //       return cur_idx;
  //     }
  //     if (heights[cur_idx] >= heights[cur_idx + 1]) {
  //       return jump(heights, cur_idx + 1, bricks, ladders);
  //     }

  //     // we need bricks or ladders
  //     int need_bricks = heights[cur_idx + 1] - heights[cur_idx];
  //     int use_brick_can_go_to = cur_idx;
  //     int use_ladder_can_go_to = cur_idx;
  //     if (bricks >= need_bricks) {
  //       use_brick_can_go_to =
  //           jump(heights, cur_idx + 1, bricks - need_bricks, ladders);
  //     }
  //     if (ladders > 0) {
  //       use_ladder_can_go_to = jump(heights, cur_idx + 1, bricks, ladders -
  //       1);
  //     }

  //     return max(use_brick_can_go_to, use_ladder_can_go_to);
  //   }
};
