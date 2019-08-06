// http://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
#include "xxx.h"

class Solution {
public:
  int shipWithinDays(vector<int> &weights, int D) {
    auto r = accumulate(weights.begin(), weights.end(), 0);
    auto l = max(r / D, *max_element(weights.begin(), weights.end()));

    while (l < r) {
      auto m = (l + r) / 2;
      if (countDays(weights, m) <= D) {
        r = m;
      } else {
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
