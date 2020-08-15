// http://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
#include "xxx.h"

class Solution {
public:
  int shipWithinDays(vector<int> &weights, int D) {
    // 口袋最大就是一次全吃，那就是装所有
    auto r = accumulate(weights.begin(), weights.end(), 0);
    // 口袋最小那就是至少能装起来最大的那个
    auto l = max(r / D, *max_element(weights.begin(), weights.end()));

    while (l < r) {
      auto m = (l + r) / 2;
      // 需要的口袋少了，那说明口袋敞口偏大，缩一缩
      if (countDays(weights, m) <= D) {
        r = m;
      } else {
        // 否则口袋用多了，那就是口子小，放一放
        l = m + 1;
      }
    }

    return l;
  }

private:
  int countDays(vector<int> &ws, int total_cap) {
    int ret = 1;
    int cur_cap = 0;

    for (auto w : ws) {
      cur_cap += w;
      if (cur_cap > total_cap) {
        ++ret;
        cur_cap = w;
      }
    }

    return ret;
  }
};
