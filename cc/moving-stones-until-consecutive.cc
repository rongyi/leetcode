// http://leetcode.com/problems/moving-stones-until-consecutive/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> lst{a, b, c};
    sort(lst.begin(), lst.end());
    a = lst[0];
    b = lst[1];
    c = lst[2];
    if (c - a == 2) {
      return {0, 0};
    }
    int min_move = 2;
    if (min(b - a, c - b) <= 2) {
      min_move = 1;
    }
    return {min_move, c - a - 2};
  }
};
