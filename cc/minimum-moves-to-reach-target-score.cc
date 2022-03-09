// https://leetcode.com/problems/minimum-moves-to-reach-target-score/
#include "xxx.hpp"

class Solution {
public:
  int minMoves(int target, int numd) {
    int op_count = 0;
    while (numd > 0 && target > 1) {
      if (target & 1) {
        --target;
        ++op_count;
      }
      --numd;
      ++op_count;
      target /= 2;
    }

    return op_count + (target - 1);
  }
};
