// http://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/
#include "xxx.h"

class Solution {
public:
  Solution(vector<vector<int>> rects) {
    rects_ = rects;
    int total = 0;
    for (int i = 0; i < rects_.size(); i++) {
      /*
       * What we need to be aware of here is that the input may contain
       * lines that are not rectangles. For example, [1, 2, 1, 5], [3, 2, 3,
       * -2].
       *
       * So, we work around it by adding +1 here. It does not affect
       * the final result of reservoir sampling.
       */
      total +=
          (rects_[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
      areas_.push_back(total);
    }
    total_area_ = total;
  }

  vector<int> pick() {
    int random_area = rand() % total_area_ + 1;
    int i = 0;
    for (; i < areas_.size(); i++) {
      if (random_area <= areas_[i]) {
        break;
      }
    }
    int x = rand() % (rects_[i][2] - rects_[i][0] + 1);
    int y = rand() % (rects_[i][3] - rects_[i][1] + 1);

    return {rects_[i][0] + x, rects_[i][1] + y};
  }

private:
  vector<vector<int>> rects_;
  vector<int> areas_;
  int total_area_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */
