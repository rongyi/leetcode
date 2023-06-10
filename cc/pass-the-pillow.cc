// https://leetcode.com/problems/pass-the-pillow/
#include "xxx.hpp"

class Solution {
public:
  int passThePillow(int n, int time) {
    int gap = n - 1;
    int round = time / gap;
    int rem = time % gap;
    if (round & 1) {
      return n - rem;
    }
    return 1 + rem;
  }
};
