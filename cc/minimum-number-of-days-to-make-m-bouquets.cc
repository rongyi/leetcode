// http://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
#include "xxx.h"

class Solution {
public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    if (m * k > bloomDay.size()) {
      return -1;
    }

    auto lo = 1;
    int hi = pow(10, 9);
    while (lo < hi) {
      auto mid = (lo + hi) / 2;
      if (canHavest(bloomDay, mid, m, k)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }

private:
  // 每束花有k支相邻的花朵组成，有m束花, 看看满足条件的是否有m束
  bool canHavest(vector<int> &bday, int curday, int m, int k) {
    int count = 0;
    for (auto &d : bday) {
      if (d <= curday) {
        count++;
        if (count >= k) {
          count = 0;
          --m;
        }
      } else {
        count = 0;
      }
    }

    return m <= 0;
  }
};
