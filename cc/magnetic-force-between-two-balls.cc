// http://leetcode.com/problems/magnetic-force-between-two-balls/description/
#include "xxx.h"

class Solution {
public:
  int maxDistance(vector<int> &position, int m) {
    sort(position.begin(), position.end());
    const int n = position.size();
    auto count = [&](int d) -> int {
      int ret = 1;
      int cur = position[0];
      for (int i = 1; i < n; ++i) {
        if (position[i] - cur >= d) {
          ++ret;
          cur = position[i];
        }
      }
      return ret;
    };
    int l = 0;
    int r = position[n - 1] - position[0];
    while (l < r) {
      auto mid = r - (r - l) / 2;
      // it depends on whether you are trying to find the min value satisfying
      // some criteria or the max value. I usually use m = l + (r-l)//2 for
      // bisect_left and the other one for bisect_right.

      // As a rule of thumb, use
      // m = l + (r-l)//2 with l = m + 1 and r = m, and use m = r - (r-l)//2
      // with l = m and r = m - 1. This can prevent m from stucking at r (or l)
      // after the updating step.
      if (count(mid) >= m) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }

    return l;
  }
};
