// http://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/
#include "xxx.h"

class Solution {
public:
  vector<int> sortByBits(vector<int> &arr) {
    auto count1 = [](int n) -> int {
      int ret = 0;
      while (n) {
        ++ret;
        n &= n - 1;
      }

      return ret;
    };

    // 先按照1个数排序，然后再按照大小排序
    sort(arr.begin(), arr.end(), [&](int &l, int &r) -> bool {
      auto l1 = count1(l);
      auto r1 = count1(r);
      if (l1 == r1) {
        return l < r;
      }
      return l1 < r1;
    });
    return arr;
  }
};
