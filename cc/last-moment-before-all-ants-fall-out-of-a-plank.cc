// http://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/
#include "xxx.hpp"

class Solution {
public:
  int getLastMoment(int n, vector<int> &left, vector<int> &right) {
    // 注意方向，left是往左方向行驶的，放在右边
    // 能看出来掉不掉头都无所谓即可
    auto l = 0;
    auto r = 0;
    // <====
    if (left.size() > 0) {
      l = *max_element(left.begin(), left.end());
    }
    // ====>
    if (right.size() > 0) {
      r = n - *min_element(right.begin(), right.end());
    }

    return max(l, r);
  }
};
