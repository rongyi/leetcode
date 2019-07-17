// http://leetcode.com/problems/prison-cells-after-n-days/description/
#include "xxx.h"

class Solution {
public:
  vector<int> prisonAfterNDays(vector<int> &cells, int N) {
    // 有pattern的
    N %= 14;
    if (N == 0) {
      N = 14;
    }
    vector<int> next(8, 0);
    for (int round = 0; round < N; round++) {
      for (int i = 1; i < 7; i++) {
        next[i] = (cells[i + 1] == cells[i - 1]) ? 1 : 0;
      }
      cells = next;
    }
    return next;
  }
};
