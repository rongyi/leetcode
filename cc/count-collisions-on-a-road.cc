// https://leetcode.com/problems/count-collisions-on-a-road/
#include "xxx.hpp"

class Solution {
public:
  int countCollisions(string s) {
    int sz = s.size();
    int l = 0;
    int r = sz - 1;
    while (l < sz && s[l] == 'L') {
      l++;
    }
    while (r >= 0 && s[r] == 'R') {
      r--;
    }
    int ret = 0;
    for (int i = l; i <= r; ++i) {
      if (s[i] != 'S') {
        ret++;
      }
    }
    return ret;
  }
};
