// http://leetcode.com/problems/sort-integers-by-the-power-value/description/
#include "xxx.h"

class Solution {
public:
  int getKth(int lo, int hi, int k) {
    auto p = [](int x) -> int {
      int steps = 0;
      while (x != 1) {
        if (x & 1) {
          x = 3 * x + 1;
        } else {
          x /= 2;
        }

        steps++;
      }
      return steps;
    };

    vector<int> ves;
    for (int i = lo; i <= hi; ++i) {
      ves.push_back(i);
    }
    sort(ves.begin(), ves.end(), [&p](int &l, int &r) -> bool {
      auto pl = p(l);
      auto pr = p(r);
      if (pl == pr) {
        return l < r;
      }
      return pl < pr;
    });

    return ves[k - 1];
  }
};
